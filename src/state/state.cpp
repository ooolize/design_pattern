/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */

#include "state.h"

State::StateUPtr JumpingState::handleInput(const std::string& input) {
  std::cout << "JumpingState handleInput " << input << std::endl;
  if (input == "attack") {
    return std::make_unique<DivingState>();
  }
  return std::make_unique<JumpingState>();
}

void JumpingState::update() {
  std::cout << "updateJumping" << std::endl;
}
void JumpingState::enter() {
  get_state_map()[StateType::JUMPING]();
}

State::StateUPtr StandingState::handleInput(const std::string& input) {
  std::cout << "StandingState handleInput " << input << std::endl;
  if (input == "down") {
    return std::make_unique<DuckingState>();
  } else if (input == "jump") {
    return std::make_unique<JumpingState>();
  }
  return std::make_unique<StandingState>();
}

void StandingState::update() {
  std::cout << "updateStanding" << std::endl;
}

void StandingState::enter() {
  get_state_map()[StateType::STANDING]();
}

State::StateUPtr DuckingState::handleInput(const std::string& input) {
  std::cout << "DuckingState handleInput " << input << std::endl;
  if (input == "up") {
    return std::make_unique<StandingState>();
  }
  return std::make_unique<DuckingState>();
}
void DuckingState::update() {
  std::cout << "updateDiving" << std::endl;
  charge_time++;
  if (charge_time > excharge_time) {
    superBoom();
    charge_time = 0;
  }
}

void DuckingState::enter() {
  get_state_map()[StateType::DUCKING]();
}

void DuckingState::superBoom() {
  std::cout << "superBoom" << std::endl;
}

State::StateUPtr DivingState::handleInput(const std::string& input) {
  std::cout << "DivingState handleInput " << input << std::endl;
  return std::make_unique<DivingState>();
}
void DivingState::update() {
  std::cout << "updateDivingState " << std::endl;
}

void DivingState::enter() {
  get_state_map()[StateType::DIVING]();
}
