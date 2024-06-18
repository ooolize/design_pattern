/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-14
 * @LastEditors: lize
 */

#include "strategy.h"
void Strategy::func() {
  std::cout << "Strategy::func" << std::endl;
}

int main() {
  Strategy echo;
  echo.func();
  std::cout << "main" << std::endl;

  return 0;
}