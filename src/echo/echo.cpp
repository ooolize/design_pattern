/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-14
 * @LastEditors: lize
 */

#include "echo.hpp"
void Echo::func() {
  std::cout << "Echo::func" << std::endl;
}

int main() {
  Echo echo;
  echo.func();
  std::cout << "main" << std::endl;

  return 0;
}