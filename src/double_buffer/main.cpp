/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#include <thread>

#include "double_buffer.h"
int main() {
  Scene scene;
  std::jthread t1([&scene]() {
    for (int i = 0; i < 5; ++i) {
      scene.update(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  });
  std::jthread t2([&scene]() {
    for (int i = 0; i < 500; ++i) {
      scene.getBuffer();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  });
  std::this_thread::sleep_for(std::chrono::seconds(86400));
  return 0;
}