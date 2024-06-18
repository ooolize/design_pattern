/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Drink {
 public:
  typedef std::shared_ptr<Drink> DrinkPtr;
  Drink() = default;
  Drink(const std::string& name, double price) : _name(name), _price(price){};
  const std::string& getName() const;
  double getPrice() const;

 private:
  std::string _name;
  double _price;
};

class Box {
 public:
  Box(size_t width, size_t height) : _width(width), _height(height) {
    _drink.resize(_width);
    std::for_each(
      _drink.begin(), _drink.end(), [this](auto& row) { row.resize(_height); });

    _maidong = Drink("maidong", 5.5);
    _pepsi = Drink("pepsi", 3.5);
    _adCa = Drink("adCa", 4.5);
  }
  Drink::DrinkPtr getDrink(size_t x, size_t y) const;
  void randomDisplay();
  void show() const;

 private:
  size_t _width;
  size_t _height;
  std::vector<std::vector<Drink::DrinkPtr>> _drink;

  Drink _maidong{};
  Drink _pepsi{};
  Drink _adCa{};
};