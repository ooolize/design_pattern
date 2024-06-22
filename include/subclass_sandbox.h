/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-21
 * @LastEditors: lize
 */

#pragma once
#include <memory>
#include <string>

constexpr size_t LionMoveSteps = 10;
constexpr size_t LionSleepSeconds = 5;
constexpr size_t TigerMoveSteps = 5;
constexpr size_t TigerSleepSeconds = 10;

class Felidae {
 public:
  using FelidaeUPtr = std::unique_ptr<Felidae>;
  using FelidaeSptr = std::shared_ptr<Felidae>;
  virtual ~Felidae() noexcept = default;
  virtual void act() = 0;

 protected:
  void move(size_t steps);
  void sleep(size_t seconds);
};

class Lion : public Felidae {
 public:
  void act() override;

 private:
  std::string _name = "Lion";
};
class Tiger : public Felidae {
 public:
  void act() override;

 private:
  std::string _name = "Tiger";
};