/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include <map>
#include <thread>

#include "component.h"

constexpr size_t sleep_time_ms = 1000;
constexpr size_t loop_num = 10;
int main() {
  GameObject game_object(std::make_shared<LinearComponent>(1.0),
                         std::make_shared<DrawSingle>("=>"));
  for (size_t i = 0; i < loop_num; i++) {
    system("cls");
    game_object.update();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
  }
}