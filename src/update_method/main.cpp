/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#include <thread>

#include "update_method.h"
int main() {
  World world;
  world.addEntity(std::make_unique<Bullet>(0, 0));
  world.addEntity(std::make_unique<Bullet>(1, 0));
  world.addEntity(std::make_unique<Cloud>(4, 4));
  while (true) {
    system("cls");
    world.gameLoop();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  return 0;
}