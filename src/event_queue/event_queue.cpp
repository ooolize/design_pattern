/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-22
 * @LastEditors: lize
 */
#include "event_queue.h"
template <typename T>
void EventQueue<T>::push_and_merge(TUptr message) {
  for (auto& msg : _queue) {
    if (message && msg && msg->type == message->type) {
      msg->volume = std::max(msg->volume, message->volume);
      return;
    }
  }

  _queue[_tail] = std::move(message);

  _tail = (_tail + 1) % MAX_QUEUE_SIZE;
}

template <typename T>
EventQueue<T>::TUptr EventQueue<T>::pop() {
  if (_head == _tail) {
    return nullptr;
  }
  auto message = std::move(_queue[_head]);
  _head = (_head + 1) % MAX_QUEUE_SIZE;

  return message;
}

// 一个有意思的问题 这个函数是多线程安全的吗?
void Audio::PlaySound(SoundType type, size_t volume) {
  auto message = std::make_unique<Message>();
  message->type = type;
  message->volume = volume;

  // 合并同类型的声音
  _event_queue.push_and_merge(std::move(message));
  std::cout << ">>>>push sound type: " << type << " volume: " << volume
            << std::endl;
}

void Audio::update() {
  if (_event_queue.is_empty()) {
    return;
  }
  auto message = _event_queue.pop();
  if (message) {
    std::cout << "<<<<<pop sound type: " << message->type
              << " volume: " << message->volume << std::endl;
  }
}