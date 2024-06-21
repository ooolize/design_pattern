/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include <thread>

#include "type_object.h"
int main() {
  Breed::BreedSPtr parent = std::make_shared<Breed>(10, 20);
  Breed::BreedSPtr child = std::make_shared<Breed>(0, 0, parent);
  Monster monster = child->createMonster();
  Breed& breed = monster.getBreed();
  breed.show();
  return 0;
}