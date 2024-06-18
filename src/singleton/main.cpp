/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "singleton.h"

int main() {
  A& instance1 = Singleton<A>::getInstance();
  A& instance2 = Singleton<A>::getInstance();
  instance1.func();
  instance2.func();
  std::cout << &instance1 << " " << &instance2 << std::endl;
  return 0;
}