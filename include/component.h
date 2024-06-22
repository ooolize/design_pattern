/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-22
 * @LastEditors: lize
 */
#pragma once
#include <memory>
#include <string>
class GameObject;
class PhysicsComponent {
 public:
  using PhysicsComponentPtr = std::shared_ptr<PhysicsComponent>;
  virtual void update(GameObject&) = 0;
  virtual ~PhysicsComponent() noexcept = default;
};

class LinearComponent : public PhysicsComponent {
 public:
  LinearComponent(double speed);
  void update(GameObject&) override;

 private:
  double _speed = 1.0;
};
class GraphicsComponent {
 public:
  using GraphicsComponentPtr = std::shared_ptr<GraphicsComponent>;

  virtual void update(GameObject&) = 0;
  virtual ~GraphicsComponent() noexcept = default;
};

class DrawSingle : public GraphicsComponent {
 public:
  void update(GameObject&) override;
  DrawSingle(std::string sprite);

 private:
  std::string _char = "=>";
};

class GameObject {
 public:
  GameObject(PhysicsComponent::PhysicsComponentPtr,
             GraphicsComponent::GraphicsComponentPtr);
  void update();
  int _x = 0;

 private:
  PhysicsComponent::PhysicsComponentPtr _physics_component;
  GraphicsComponent::GraphicsComponentPtr _graphics_component;
};