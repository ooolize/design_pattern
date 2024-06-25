/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */

#include "server_locator.h"

#include <iostream>

LogServer::ServerSPtr ServerLocaltor::_server =
  std::make_shared<NullLogServer>();

void NullLogServer::info(const std::string& msg) {
  std::cout << "NullLogServer info: " << std::endl;
}

void NullLogServer::warn(const std::string& msg) {
  std::cout << "NullLogServer warn: " << std::endl;
}

void SimpleLogServer::info(const std::string& msg) {
  std::cout << "info: " << _seq << msg << std::endl;
}

void SimpleLogServer::warn(const std::string& msg) {
  std::cout << "warn: " << _seq << msg << std::endl;
}

SimpleLogServer::SimpleLogServer(const std::string& seq) : _seq(seq) {
}

LogServer::ServerSPtr ServerLocaltor::getServer() {
  if (!_server) {
    _server = std::make_shared<NullLogServer>();
  }
  return _server;
}

CountLogServer::CountLogServer(LogServer& server)
  : _wrapper(server), _infoCount(0), _warnCount(0) {
}

void CountLogServer::info(const std::string& msg) {
  _wrapper.info(msg);
  ++_infoCount;
  std::cout << "_infoCount: " << _infoCount << std::endl;
}

void CountLogServer::warn(const std::string& msg) {
  _wrapper.warn(msg);
  ++_warnCount;
  std::cout << "_warnCount: " << _warnCount << std::endl;
}

void ServerLocaltor::provide(LogServer::ServerSPtr server) {
  _server = server;
}