/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-15
 * @LastEditors: lize
 */
#include <queue>
#include <thread>

#include "command.hpp"

int main() {
  std::queue<CommandPtr> commands_queue;
  RolePtr role1 = std::make_shared<Actor1>();
  InputHandler input_handler;

  input_handler.setJump(std::make_unique<JumpCommand>(role1));
  input_handler.setFire(std::make_unique<FireCommand>(role1));
  input_handler.setMove(std::make_unique<MoveCommand>(role1, 1, 2));

  commands_queue.push(input_handler.genCommand("fire"));
  commands_queue.push(input_handler.genCommand("jump"));
  commands_queue.push(input_handler.genCommand("move"));

  std::cout << "commands_queue.size() = " << commands_queue.size() << std::endl;
  std::jthread t1([&commands_queue]() {
    while (commands_queue.size() > 0) {
      auto command = std::move(commands_queue.front());
      commands_queue.pop();
      command->execute();
      command->undo();
    }
  });
  //   t1.join();
}

// 硬编码
// auto doJump = []() { std::cout << "Jump" << std::endl; };
// auto doFire = []() { std::cout << "Fire" << std::endl; };
// auto doMove = []() { std::cout << "Move" << std::endl; };
// void InputHandler(const std::string& input) {
//   if (input == "jump") {
//     doJump();
//   } else if (input == "fire") {
//     doFire();
//   } else if (input == "move") {
//     doMove();
//   }
// }

// int main() {
//   InputHandler("jump");
//   InputHandler("fire");
//   InputHandler("move");
//   return 0;
// };