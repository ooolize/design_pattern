

/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-25
 * @LastEditors: lize
 */
#include "object_pool.h"
Box::Box(size_t width, size_t height, size_t depth) : _is_use(false) {
  _box._property._width = width;
  _box._property._height = height;
  _box._property._depth = depth;
}

void Box::print() const {
  if (_is_use) {
    std::cout << "Box: " << _box._property._width << " "
              << _box._property._height << " " << _box._property._depth
              << std::endl;
  } else {
    std::cout << "Box is not use" << std::endl;
  }
}

BoxPool::BoxPool() {
  for (size_t i = 0; i < kMaxBoxSize; i++) {
    _box_pool[i] = std::make_shared<Box>();
  }
  for (size_t i = 1; i < kMaxBoxSize; i++) {
    _box_pool[i - 1]->_box._node._next = _box_pool[i].get();
    _box_pool[i]->_box._node._prev = _box_pool[i - 1].get();
  }
  _box_free = _box_pool[0];
}
void BoxPool::print() const {
  for (size_t i = 0; i < kMaxBoxSize; i++) {
    _box_pool[i]->print();
  }
  std::cout << "======================" << std::endl;
}

Box::BoxSPtr BoxPool::getBox(size_t width, size_t height, size_t depth) {
  if (_box_free) {
    Box::BoxSPtr box = _box_free;
    _box_free.reset(_box_free->_box._node._next);
    box->_box._property._width = width;
    box->_box._property._height = height;
    box->_box._property._depth = depth;
    box->_is_use = true;
    return box;
  } else {
    std::cout << "pool is full" << std::endl;
    return nullptr;
  }
}

void BoxPool::recycleBox(Box::BoxSPtr box) {
  if (box->_is_use) {
    box->_is_use = false;
    auto& free_list_front = _box_free;
    // 目前已无可用
    if (!free_list_front) {
      free_list_front = box;
      return;
    }

    box->_box._node._next = free_list_front->_box._node._next;
    box->_box._node._prev = free_list_front.get();
    free_list_front->_box._node._next = box.get();
  }
}