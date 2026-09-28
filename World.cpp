#include "World.hpp"
#include "Ball.hpp"
#include "Painter.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept> 

static constexpr double timePerTick = 0.001;

World::World(const std::string& worldFilePath) {
    std::ifstream stream(worldFilePath);
    if (!stream.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + worldFilePath);
    }

    stream >> topLeft >> bottomRight;
    physics.setWorldBox(topLeft, bottomRight);

    Color color;
    Point center;
    Velocity velocity;
    double radius;
    bool isCollidable;

    while (stream >> center >> velocity >> color >> radius >> std::boolalpha >>
           isCollidable) {
     
        balls.push_back(Ball(center, velocity, radius, color, isCollidable));
    }
} 

void World::show(Painter& painter) const {
    
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    for (const Ball& ball : balls) {
        ball.draw(painter);
    }
}

void World::update(double time) {
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    physics.update(balls, ticks);
}