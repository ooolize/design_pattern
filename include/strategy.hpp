/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-14
 * @LastEditors: lize
 */
#pragma once
#include <iostream>
class Strategy {
 public:
  Strategy() {
    std::cout << "Strategy" << std::endl;
  };
  ~Strategy() {
    std::cout << "~Strategy" << std::endl;
  };

  void func();
};