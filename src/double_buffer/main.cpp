/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#include <thread>

#include "double_buffer.h"
constexpr size_t loop_n = 5;
constexpr size_t sleep_n = 10;
constexpr size_t multiple = 100;
constexpr size_t main_sleep = sleep_n * 1000;
int main() {
  Scene scene;
  std::jthread t1([&scene]() {
    for (int i = 0; i < loop_n; ++i) {
      scene.update(i);
      std::this_thread::sleep_for(
        std::chrono::milliseconds(sleep_n * multiple));
    }
  });
  std::jthread t2([&scene]() {
    for (int i = 0; i < n * multiple; ++i) {
      scene.getBuffer();
      std::this_thread::sleep_for(std::chrono::milliseconds(sleep_n));
    }
  });
  std::this_thread::sleep_for(std::chrono::seconds(main_sleep));
  return 0;
}