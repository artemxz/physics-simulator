#include "Ball.hpp"
#include <cmath>


Ball::Ball(const Point& center, const Velocity& velocity, double radius,const Color& color, bool isCollidable) :            
    velocity_(velocity),color_(color), center_(center),radius_(radius),  isCollidable_(isCollidable) 
{  
   mass_ = M_PI * radius * radius * radius * 4.0 / 3.0; 
}


Velocity Ball::getVelocity() const {
    
    return velocity_;
}

void Ball::setVelocity(const Velocity& velocity) {

    velocity_ = velocity;
}

 
void Ball::draw(Painter& painter) const {
    painter.draw(center_, radius_, color_);
}


void Ball::setCenter(const Point& center) {
    center_ = center;
}

Point Ball::getCenter() const {
    
    return center_;
}


double Ball::getRadius() const {
    
    return radius_;
}


double Ball::getMass() const {
    
    return mass_;
}
