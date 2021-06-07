#ifndef BALL_H
#define BALL_H

#include "GL/gl.h"
#include <cmath>
#include <ctime>

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

private:
    void checkCollisions();
};

#endif