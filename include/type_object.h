/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */

#pragma once
#include <memory>

class Monster;
class Breed {
 public:
  using BreedSPtr = std::shared_ptr<Breed>;
  Breed(int health, int attack, BreedSPtr parent = nullptr);
  Monster createMonster();
  void show() const;

 private:
  int _health;
  int _attack;
  BreedSPtr _parent;
};
class Monster {
  friend class Breed;

 public:
  Breed& getBreed();

 private:
  Monster(Breed& breed);
  Breed& breed;
};