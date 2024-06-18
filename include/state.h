/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */
#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
enum StateType {
  JUMPING,
  STANDING,
  DUCKING,
  DIVING,
};

class State {
 public:
  typedef std::unique_ptr<State> StateUPtr;
  virtual ~State() = default;
  virtual StateUPtr handleInput(const std::string&) = 0;
  virtual void update() = 0;
  virtual void enter() = 0;
};

class JumpingState : public State {
 public:
  StateUPtr handleInput(const std::string&) override;
  void update() override;
  void enter() override;
};

class StandingState : public State {
 public:
  StateUPtr handleInput(const std::string&) override;
  void update() override;
  void enter() override;
};

class DuckingState : public State {
 public:
  StateUPtr handleInput(const std::string&) override;
  void update() override;
  void enter() override;
  void superBoom();

 private:
  int charge_time = 0;
};

class DivingState : public State {
 public:
  StateUPtr handleInput(const std::string&) override;
  void update() override;
  void enter() override;
};

class Mechine {
 public:
  Mechine() {
    state_ptr = std::make_unique<StandingState>();
  }
  void handleInput(const std::string& input) {
    auto new_state = state_ptr->handleInput(input);
    if (new_state) {
      state_ptr = std::move(new_state);
      state_ptr->enter();
    }
  };
  void update() {
    state_ptr->update();
  };

 private:
  State::StateUPtr state_ptr;
};