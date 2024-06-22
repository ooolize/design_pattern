/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-22
 * @LastEditors: lize
 */
#pragma once
#include <atomic>
#include <iostream>
#include <memory>
#include <vector>
enum SoundType {
  ActtackSound,
  SleepSound,
  DeadSound,
};
struct Message {
  SoundType type;
  size_t volume;
};
constexpr size_t MAX_QUEUE_SIZE = 100;

template <typename T>
class EventQueue {
 public:
  using TUptr = std::unique_ptr<T>;
  using TSptr = std::shared_ptr<T>;
  EventQueue() {
    _queue.resize(MAX_QUEUE_SIZE);
    _head = 0;
    _tail = 0;
  }
  void push_and_merge(TUptr message);
  TUptr pop();
  bool is_empty() const {
    return _head == _tail;
  }

 private:
  size_t _head = 0;
  size_t _tail = 0;
  std::vector<TUptr> _queue;
};
class Audio {
 public:
  Audio() = default;
  void PlaySound(SoundType type, size_t volume);
  void update();

 private:
  EventQueue<Message> _event_queue;
};