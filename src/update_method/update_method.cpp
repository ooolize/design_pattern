/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-20
 * @LastEditors: lize
 */
#include "update_method.h"

#include <iostream>

Bullet::Bullet(size_t x, size_t y) : x(x), y(y) {
}
void Bullet::update() {
  // std::cout << "bullet update" << std::endl;
  x++;
  // y++;
}
void Bullet::show() {
  for (size_t i = 0; i < y; i++) {
    std::cout << std::endl;
  }
  for (size_t i = 0; i < x; i++) {
    std::cout << " ";
  }
  std::cout << "=>" << std::endl;
}

void Cloud::update() {
  // std::cout << "cloud update" << std::endl;

  if (_width > 0 && _height > 0) {
    _width--;
    _height--;
  }
}
void Cloud::show() {
  for (size_t i = 0; i < _height; i++) {
    for (size_t j = 0; j < _width; j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}
void World::update() {
  for (auto& entity : entities) {
    entity->update();
  }
}
void World::gameLoop() {
  update();
  show();
}
void World::show() {
  for (auto& entity : entities) {
    entity->show();
  }
}

void World::addEntity(Entity::EntityUPtr entity) {
  entities.push_back(std::move(entity));
}