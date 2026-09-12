#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"
#include "Color.hpp"

class Ball {
private:
    Velocity velocity_;
    Point center_;
    double radius_;
    Color color_;
    bool isCollidable_;
    double mass_;
public:
    Ball(const Point& center, const Velocity& velocity, double radius, const Color& color, bool isCollidable);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
};
