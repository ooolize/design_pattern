/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */
#pragma once
#include "singleton.h"

template <typename T>
T& Singleton<T>::getInstance() {
  static T instance;
  return instance;
}
template class Singleton<A>;