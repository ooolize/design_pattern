/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-15
 * @LastEditors: lize
 */
#pragma once
#include <iostream>
#include <memory>
#include <string>

class Role;
class Command;
using RolePtr = std::shared_ptr<Role>;
using CommandPtr = std::unique_ptr<Command>;

class Role {
 public:
  virtual ~Role() = default;
  virtual void jump() = 0;
  virtual void fire() = 0;
  virtual void move(int x, int y) = 0;
  int get_x();
  int get_y();

 private:
  int x = 0;
  int y = 0;
};
class Actor1 : public Role {
 public:
  void jump() override;
  void fire() override;
  void move(int x, int y);
};

class Command {
 public:
  Command(RolePtr role) : role(role) {
  }
  virtual ~Command() = default;
  virtual void execute() = 0;
  virtual void undo() = 0;
  RolePtr role;
};

class JumpCommand : public Command {
 public:
  JumpCommand() = default;
  JumpCommand(RolePtr role) : Command(role){};
  void execute() override;
  void undo() override;
};

class FireCommand : public Command {
 public:
  FireCommand() = default;
  FireCommand(RolePtr role) : Command(role){};
  void execute() override;
  void undo() override;
};

class MoveCommand : public Command {
 public:
  MoveCommand(RolePtr role, int x, int y)
    : Command(role), target_x(x), target_y(y){};
  void execute() override;
  void undo() override;

 private:
  int target_x = 0;
  int target_y = 0;
  int before_x = 0;
  int before_y = 0;
};

class InputHandler {
 public:
  CommandPtr genCommand(const std::string& input);

  void setJump(CommandPtr jump_command);
  void setFire(CommandPtr fire_command);
  void setMove(CommandPtr move_command);

 private:
  CommandPtr m_jump_command;
  CommandPtr m_fire_command;
  CommandPtr m_move_command;
};
