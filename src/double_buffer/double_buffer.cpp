/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */

#include "double_buffer.h"

#include <algorithm>
#include <iostream>

FrameBuffer::FrameBuffer(size_t width, size_t height)
  : _width(width), _height(height) {
  _buffer.resize(width * height);
}

int FrameBuffer::getPxiel(size_t x, size_t y) const {
  return _buffer[y * _width + x];
}

void FrameBuffer::setPixel(size_t x, size_t y, int color) {
  _buffer[y * _width + x] = color;
}

void FrameBuffer::clear() {
  std::fill(_buffer.begin(), _buffer.end(), 0);
}

void FrameBuffer::getBuffer() {
  for (size_t y = 0; y < _height; ++y) {
    for (size_t x = 0; x < _width; ++x) {
      std::cout << getPxiel(x, y) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "================================" << std::endl;
}

Scene::Scene() {
  current_buffer = std::make_unique<FrameBuffer>();
  next_buffer = std::make_unique<FrameBuffer>();
}

void Scene::draw(int i) {
  for (size_t y = 0; y < n; ++y) {
    for (size_t x = 0; x < n; ++x) {
      current_buffer->setPixel(x, y, i);
    }
  }
}

void Scene::swap() noexcept {
  std::swap(current_buffer, next_buffer);
}

void Scene::update(int i) {
  draw(i);
  swap();
}

void Scene::getBuffer() {
  current_buffer->getBuffer();
}