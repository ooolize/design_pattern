/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */
#include <map>
#include <thread>

#include "type_object.h"

constexpr std::pair<int, int> breed1 = {10, 20};
int main() {
  Breed::BreedSPtr parent =
    std::make_shared<Breed>(breed1.first, breed1.second);
  Breed::BreedSPtr child = std::make_shared<Breed>(0, 0, parent);
  Monster monster = child->createMonster();
  Breed& breed = monster.getBreed();
  breed.show();
  return 0;
}