/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "server_locator.h"

int main() {
  // null
  auto server = ServerLocaltor::getServer();
  server->info("hello");
  server->warn("world");

  auto p1 = std::make_shared<SimpleLogServer>("|");
  ServerLocaltor::provide(p1);
  // A 如果写成 将以上两步和一 会有悬空引用的问题!
  server = ServerLocaltor::getServer();
  server->info("hello");
  server->warn("world");

  // 如果在A处合并代码。
  // 当provide后，旧的_server被销毁。即引用绑定的对象被销毁了，
  // 此时CountLogServer内_wrapper是悬挂引用
  ServerLocaltor::provide(std::make_shared<CountLogServer>(*server));
  server = ServerLocaltor::getServer();
  server->info("hello");
  return 0;
}