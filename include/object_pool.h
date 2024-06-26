/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-26
 * @LastEditors: lize
 */
#pragma once
#include <iostream>
#include <memory>
class Box {
 public:
  friend class BoxPool;
  using BoxUPtr = std::unique_ptr<Box>;
  using BoxSPtr = std::shared_ptr<Box>;
  void print() const;

  Box(size_t width = 0, size_t height = 0, size_t depth = 0);

 private:
  bool _is_use;
  union BoxUnion {
    struct BoxProperty {
      size_t _width;
      size_t _height;
      size_t _depth;
      size_t _padding;
    } _property;
    struct BoxNode {
      Box* _next;  // union内不能用smart pointer,
      Box* _prev;
    } _node;
  } _box;
};

constexpr size_t kMaxBoxSize = 3;
class BoxPool {
 public:
  BoxPool();
  Box::BoxSPtr getBox(size_t width, size_t height, size_t depth);
  void recycleBox(Box::BoxSPtr box);
  void print() const;

 private:
  Box::BoxSPtr _box_free = nullptr;
  Box::BoxSPtr _box_pool[kMaxBoxSize];
};
