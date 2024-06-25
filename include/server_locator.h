/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-25
 * @LastEditors: lize
 */
#pragma once
#include <memory>
#include <string>
class LogServer {
 public:
  using ServerUPtr = std::unique_ptr<LogServer>;
  using ServerSPtr = std::shared_ptr<LogServer>;
  virtual void info(const std::string& msg) = 0;
  virtual void warn(const std::string& msg) = 0;
  virtual ~LogServer() = default;
};

class SimpleLogServer : public LogServer {
 public:
  SimpleLogServer(const std::string& seq);
  void info(const std::string& msg);
  void warn(const std::string& msg);

 private:
  std::string _seq;
};

class NullLogServer : public LogServer {
 public:
  void info(const std::string& msg);
  void warn(const std::string& msg);
};

class CountLogServer : public LogServer {
 public:
  CountLogServer(LogServer& server);
  void info(const std::string& msg);
  void warn(const std::string& msg);

 private:
  LogServer& _wrapper;
  int _infoCount;
  int _warnCount;
};

class ServerLocaltor {
 public:
  static LogServer::ServerSPtr getServer();
  static void provide(LogServer::ServerSPtr server);

 private:
  static LogServer::ServerSPtr _server;
};