#pragma once
#include "Color.hpp"
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"
#include <random> 
class Dust {
  private:
    Point center_;
    Velocity velocity_; 
    Color color_;

    double lifetime_;
    double radius_;
   
  public:
    Dust(const Point& center, const Velocity& velocity, const Color& color);

    void update (double deltaTime);
    void draw  (Painter& painter) const;
    bool isAlive() const;
};

Dust::Dust(const Point& center, const Velocity& velocity, const Color& color)
    : center_(center), velocity_(velocity), color_(color) {
    lifetime_ = 1.5; // пусть время жизни каждой частички тоже отличается, сюда пишем формулу рандома? и библиотеку надо сюда подключить но не помню, между 1~1.5
    radius_ = 0.5; // 0.5~1
   
}
    

