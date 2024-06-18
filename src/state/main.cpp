/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */

#include <vector>

#include "state.h"
std::map<StateType, std::function<void()>> state_map = {
  {JUMPING, []() { std::cout << "dealJumping" << std::endl; }},
  {STANDING, []() { std::cout << "dealStanding" << std::endl; }},
  {DUCKING, []() { std::cout << "dealDucking" << std::endl; }},
  {DIVING, []() { std::cout << "dealDiving" << std::endl; }},
};
int main() {
  Mechine mechine;
  std::vector<std::string> inputs = {"down", "up", "jump", "attack"};
  for (const auto& input : inputs) {
    mechine.handleInput(input);
    // mechine.update();
  }
}