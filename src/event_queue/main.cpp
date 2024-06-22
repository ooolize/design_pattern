/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include <map>
#include <thread>

#include "event_queue.h"

constexpr size_t main_thread_sleep_s = 3000;
constexpr size_t pop_thread_sleep_s = 1;
constexpr size_t push_thread_sleep_s = 2;
constexpr size_t loop_n = 30;
int main() {
  Audio audio;

  std::jthread t1([&audio] {
    for (size_t i = 0; i < loop_n; i++) {
      audio.PlaySound(SoundType::ActtackSound, 10);
      audio.PlaySound(SoundType::SleepSound, 30);
      audio.PlaySound(SoundType::DeadSound, 40);
      std::this_thread::sleep_for(std::chrono::seconds(push_thread_sleep_s));
    }
  });

  std::jthread t2([&audio] {
    for (size_t i = 0; i < loop_n; i++) {
      audio.update();
      std::this_thread::sleep_for(std::chrono::seconds(pop_thread_sleep_s));
    }
  });

  std::this_thread::sleep_for(std::chrono::seconds(main_thread_sleep_s));
}