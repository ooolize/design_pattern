/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#pragma once

#include <memory>
#include <vector>

constexpr size_t n = 10;
class FrameBuffer {
 public:
  typedef std::unique_ptr<FrameBuffer> FrameBufferUPtr;
  FrameBuffer(size_t width = 10, size_t height = 10);
  int getPxiel(size_t x, size_t y) const;
  void setPixel(size_t x, size_t y, int color);
  void getBuffer();
  void clear();

 private:
  std::vector<int> _buffer;
  size_t _width;
  size_t _height;
};

class Scene {
 public:
  Scene();
  void draw(int i);
  void getBuffer();
  void swap() noexcept;
  void update(int i);

 private:
  FrameBuffer::FrameBufferUPtr current_buffer;
  FrameBuffer::FrameBufferUPtr next_buffer;
};