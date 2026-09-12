#include "Ball.hpp"
#include <cmath>

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
Ball::Ball(const Point& center, const Velocity& velocity, double radius,const Color& color, bool isCollidable) :            
    velocity_(velocity),color_(color), center_(center),radius_(radius),  isCollidable_(isCollidable) 
{  
   mass_ = M_PI * radius * radius * radius * 4.0 / 3.0; // не сразу понял что M_PI это число ПИ
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    // TODO: место для доработки
    return velocity_;
}

void Ball::setVelocity(const Velocity& velocity) {

    velocity_ = velocity;
}

    /**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(center_, radius_, color_);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    center_ = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    // TODO: место для доработки
    return center_;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    // TODO: место для доработки
    return radius_;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.  --------------------- PI что это
 */
double Ball::getMass() const {
    // TODO: место для доработки
    return mass_;
}
