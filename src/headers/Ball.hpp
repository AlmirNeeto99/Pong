#ifndef BALL_H
#define BALL_H

#include "GL/gl.h"
#include <cmath>
#include <ctime>
#include "Paddle.hpp"

class Ball
{
public:
    int x, y, radius, vx, vy;
    Ball(int x, int y, int radius);
    ~Ball();
    void update();
    void draw();
    void checkCollidedLimits();
    void changeDirection();
    void collidedPaddle(Paddle *paddle);

private:
    void checkCollisions();
    void center();
    void calculateDirection();
};

#endif