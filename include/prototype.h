/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-18
 * @LastEditors: lize
 */
#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
enum CommodityType : size_t { MAIDONG, PEPSI, ADCA, SHREDDED };
class Repository;
extern Repository repo;

class Commodity {
 public:
  typedef std::shared_ptr<Commodity> CommoditySptr;

  Commodity() = default;
  Commodity(const std::string& name, double price);
  virtual ~Commodity() = default;
  const std::string& getName() const;
  double getPrice() const;

 private:
  std::string _name;
  double _price;
};

class Drink : public Commodity {
 public:
  typedef std::shared_ptr<Drink> DrinkPtr;
  Drink() = default;
  Drink(const std::string& name, double price);
};

class Snack : public Commodity {
 public:
  typedef std::shared_ptr<Snack> SnackPtr;
  Snack() = default;
  Snack(const std::string& name, double price, size_t count);

 private:
  // 小吃是袋装的，记录数量!
  size_t _count;
};

class Box {
 public:
  typedef std::unique_ptr<Box> BoxUPtr;
  Box(size_t width, size_t height);
  virtual ~Box() = default;
  virtual BoxUPtr clone() = 0;
  virtual void show() const = 0;
  size_t _width;
  size_t _height;
};

class SnackBox : public Box {
 public:
  SnackBox(size_t width, size_t height);
  BoxUPtr clone() override;
  void show() const override;

 private:
  std::vector<Commodity::CommoditySptr> _snack;
};

class DrinkBox : public Box {
 public:
  DrinkBox(size_t width, size_t height);
  BoxUPtr clone() override;
  // Drink::DrinkPtr getDrink(size_t x, size_t y) const;
  void show() const override;

 private:
  void randomDisplay();

  std::vector<std::vector<Commodity::CommoditySptr>> _drink;
};

class Repository {
 public:
  Repository() = default;
  ~Repository() = default;
  void addBox(Box::BoxUPtr box) {
    _box.push_back(std::move(box));
  }

  void addCommotity(size_t seq, Commodity::CommoditySptr goods) {
    commodity_type[seq] = goods;
  }

  Commodity::CommoditySptr getCommotity(size_t seq) {
    return commodity_type[seq];
  }

  void show() const {
    std::cout << _box.size() << std::endl;
    for (auto& box : _box) {
      box->show();
    }
  }

 private:
  std::vector<Box::BoxUPtr> _box;
  std::map<size_t, Commodity::CommoditySptr> commodity_type;
};