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
  Drink() = default;
  Drink(const std::string& name, double price);
};

class Snack : public Commodity {
 public:
  Snack() = default;
  Snack(const std::string& name, double price, bool is_spicy);

 private:
  bool _is_spicy;
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
    for (auto& m : commodity_type) {
      std::cout << m.first << " " << m.second->getName() << m.second.get()
                << std::endl;
    }
    std::cout << "box size : " << _box.size() << std::endl;
    std::cout << "----------" << std::endl;
    for (size_t i = 0; i < _box.size(); ++i) {
      // 不同盒子指针 预计是不同的
      std::cout << "=== box: " << i << " " << _box[i].get() << std::endl;
      _box[i]->show();
    }
  }

 private:
  // box是独一无二的 为了验证原型模式
  std::vector<Box::BoxUPtr> _box;

  // 商品是复用的 为了验证享元模式
  std::map<size_t, Commodity::CommoditySptr> commodity_type;
};