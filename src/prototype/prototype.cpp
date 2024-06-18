/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "prototype.h"

#include <random>

Commodity::Commodity(const std::string& name, double price)
  : _name(name), _price(price) {
}

const std::string& Commodity::getName() const {
  return _name;
}
double Commodity::getPrice() const {
  return _price;
}

Drink::Drink(const std::string& name, double price) : Commodity(name, price) {
}

Snack::Snack(const std::string& name, double price, bool is_spicy)
  : Commodity(name, price), _is_spicy(is_spicy) {
}

Box::Box(size_t width, size_t height) : _width(width), _height(height) {
}

SnackBox::SnackBox(size_t width, size_t height) : Box(width, height) {
  for (size_t i = 0; i < height; i++) {
    for (size_t i = 0; i < width; i++) {
      _snack.push_back(repo.getCommotity(CommodityType::SHREDDED));
    }
  }
}

Box::BoxUPtr SnackBox::clone() {
  return std::make_unique<SnackBox>(*this);
}
void SnackBox::show() const {
  std::cout << "SnackBox size = " << _snack.size() << std::endl;
}

DrinkBox::DrinkBox(size_t width, size_t height) : Box(width, height) {
  _drink.resize(_width);
  std::for_each(
    _drink.begin(), _drink.end(), [this](auto& row) { row.resize(_height); });
  randomDisplay();
}

// Drink::DrinkPtr DrinkBox::getDrink(size_t x, size_t y) const {
//   std::cout << "x: " << x << " y: " << y << "name: " <<
//   _drink[x][y]->getName()
//             << " price: " << _drink[x][y]->getPrice() << std::endl;
//   return _drink[x][y];
// }

void DrinkBox::randomDisplay() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 2);

  for (auto& row : _drink) {
    for (auto& cell : row) {
      auto num = dis(gen);
      switch (num) {
        case 0:
          cell = repo.getCommotity(CommodityType::MAIDONG);
          break;
        case 1:
          cell = repo.getCommotity(CommodityType::PEPSI);
          break;
        case 2:
          cell = repo.getCommotity(CommodityType::ADCA);
          break;
        default:
          break;
      }
    }
  }
}

Box::BoxUPtr DrinkBox::clone() {
  return std::make_unique<DrinkBox>(*this);
}

void DrinkBox::show() const {
  for (auto& row : _drink) {
    // 相同类型的饮料 所指向的地址预计是一样的
    for (auto& cell : row) {
      std::cout << cell->getName() << cell.get() << " ";
    }
    std::cout << std::endl;
  }
}
