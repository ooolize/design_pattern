/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include <thread>

#include "subclass_sandbox.h"
auto main() -> int {
  Felidae::FelidaeUPtr lion = std::make_unique<Lion>();
  Felidae::FelidaeUPtr tiger = std::make_unique<Tiger>();
  lion->act();
  tiger->act();
}