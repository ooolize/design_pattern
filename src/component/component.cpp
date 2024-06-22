/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-22
 * @LastEditors: lize
 */
#include "component.h"

#include <iostream>
GameObject::GameObject(
  PhysicsComponent::PhysicsComponentPtr physics_component,
  GraphicsComponent::GraphicsComponentPtr graphics_component)
  : _physics_component(physics_component),
    _graphics_component(graphics_component) {
}

void GameObject::update() {
  _physics_component->update(*this);
  _graphics_component->update(*this);
}

LinearComponent::LinearComponent(double speed) : _speed(speed) {
}

void LinearComponent::update(GameObject& game_object) {
  game_object._x += _speed;
}

DrawSingle::DrawSingle(std::string ch) : _char(ch) {
}

void DrawSingle::update(GameObject& game_object) {
  for (int i = 0; i < game_object._x; i++) {
    std::cout << " ";
  }
  std::cout << _char << std::endl;
}