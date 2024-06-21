/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */

#include "type_object.h"

#include <iostream>

Breed::Breed(int health, int attack, BreedSPtr parent)
  : _health(health), _attack(attack), _parent(parent) {
  if (_health == 0 && _parent != nullptr) {
    _health = _parent->_health;
  }
  if (_attack == 0 && _parent != nullptr) {
    _attack = _parent->_attack;
  }
}

void Breed::show() const {
  std::cout << "health: " << _health << ", attack: " << _attack << std::endl;
}
Monster Breed::createMonster() {
  return Monster(*this);
}

Breed& Monster::getBreed() {
  return breed;
}

Monster::Monster(const Breed& breed) : breed(const_cast<Breed&>(breed)) {
}
