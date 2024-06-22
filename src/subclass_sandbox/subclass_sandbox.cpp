/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include "subclass_sandbox.h"

#include <iostream>
void Felidae::move(size_t steps) {
  std::cout << "Move " << steps << " steps" << std::endl;
}

void Felidae::sleep(size_t seconds) {
  std::cout << "Sleep " << seconds << " seconds" << std::endl;
}

void Lion::act() {
  std::cout << _name << " is acting" << std::endl;
  move(LionMoveSteps);
  sleep(LionSleepSeconds);
}

void Tiger::act() {
  std::cout << _name << " is acting" << std::endl;
  move(TigerMoveSteps);
  sleep(TigerSleepSeconds);
}