/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-15
 * @LastEditors: lize
 */
#include "command.hpp"

int Role::get_x() {
  return x;
}
int Role::get_y() {
  return y;
}

void Actor1::jump() {
  std::cout << "Actor1 Jump" << std::endl;
}
void Actor1::fire() {
  std::cout << "Actor1 Fire" << std::endl;
}
void Actor1::move(int x, int y) {
  std::cout << "Actor1 Move" << x << " " << y << std::endl;
}

void JumpCommand::execute() {
  role->jump();
}
void JumpCommand::undo() {
  // role->undo();
}

void FireCommand::execute() {
  role->fire();
}
void FireCommand::undo() {
  // role->undo();
}

void MoveCommand::execute() {
  before_x = role->get_x();
  before_y = role->get_y();
  role->move(target_x, target_y);
}
void MoveCommand::undo() {
  std::cout << "undo move to !" << before_x << " " << before_y << std::endl;
  role->move(before_x, before_y);
}

CommandPtr InputHandler::genCommand(const std::string& input) {
  if (input == "jump") {
    return std::move(m_jump_command);
  } else if (input == "fire") {
    return std::move(m_fire_command);
  } else if (input == "move") {
    return std::move(m_move_command);
  }
  return nullptr;
}

void InputHandler::setJump(CommandPtr jump_command) {
  m_jump_command = std::move(jump_command);
}

void InputHandler::setFire(CommandPtr fire_command) {
  m_fire_command = std::move(fire_command);
}

void InputHandler::setMove(CommandPtr move_command) {
  m_move_command = std::move(move_command);
}