/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-14
 * @LastEditors: lize
 */
#pragma once
#include <iostream>
class Echo {
 public:
  Echo() {
    std::cout << "Echo" << std::endl;
  };
  ~Echo() {
    std::cout << "~Echo" << std::endl;
  };

  void func();
};