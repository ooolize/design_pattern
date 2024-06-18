/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "flyweight.h"

#include <random>

const std::string& Drink::getName() const {
  return _name;
}
double Drink::getPrice() const {
  return _price;
}

void Box::randomDisplay() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 2);

  for (auto& row : _drink) {
    for (auto& cell : row) {
      auto num = dis(gen);
      switch (num) {
        case 0:
          cell = std::make_shared<Drink>("maidong", 4.5);
          break;
        case 1:
          cell = std::make_shared<Drink>("pepsi", 3.5);
          break;
        case 2:
          cell = std::make_shared<Drink>("adCa", 5.5);
          break;
        default:
          break;
      }
    }
  }
}

void Box::show() const {
  for (auto& row : _drink) {
    for (auto& cell : row) {
      std::cout << cell->getName() << " ";
    }
    std::cout << std::endl;
  }
}

Drink::DrinkPtr Box::getDrink(size_t x, size_t y) const {
  std::cout << "x: " << x << " y: " << y << "name: " << _drink[x][y]->getName()
            << " price: " << _drink[x][y]->getPrice() << std::endl;
  return _drink[x][y];
}
