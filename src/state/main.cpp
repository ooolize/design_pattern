/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */

#include <vector>

#include "state.h"

int main() {
  Mechine mechine;

  std::vector<std::string> inputs = {"down", "up", "jump", "attack"};
  for (const auto& input : inputs) {
    mechine.handleInput(input);
    // mechine.update();
  }
}