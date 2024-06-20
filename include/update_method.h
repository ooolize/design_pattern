/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#pragma once
#include <memory>
#include <vector>
class Entity {
 public:
  typedef std::unique_ptr<Entity> EntityUPtr;
  virtual ~Entity() = default;
  virtual void update() = 0;
  virtual void show() = 0;
};

class Bullet : public Entity {
 public:
  Bullet(size_t x, size_t y);

  void show() override;
  void update() override;

 private:
  size_t x;
  size_t y;
};
class Cloud : public Entity {
 public:
  Cloud(size_t width, size_t height) : _width(width), _height(height) {
  }
  void show() override;
  void update() override;

 private:
  size_t _width;
  size_t _height;
};
class World {
 public:
  void gameLoop();
  void addEntity(Entity::EntityUPtr entity);

 private:
  void update();
  void show();
  std::vector<Entity::EntityUPtr> entities;
};