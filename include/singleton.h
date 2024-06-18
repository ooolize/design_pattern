/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */
#pragma once
#include <iostream>
class A {
 public:
  A() = default;
  ~A() = default;
  void func() {
    // do something
    std::cout << "A::func()" << std::endl;
  }
};
template <typename T>
class Singleton {
 public:
  static T& getInstance();

 private:
  Singleton() = default;
  ~Singleton() = default;
};
