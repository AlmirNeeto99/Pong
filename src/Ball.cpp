#include "headers/Ball.hpp"
#include "GL/gl.h"
#include <cmath>

Ball::Ball(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

Ball::~Ball() {}

void Ball::move(int x, int y) {}

void Ball::update()
{
    this->x += 5;
    this->y += 5;
    if (this->x >= 1000 - this->radius)
        this->x = 0 + this->radius;

    if (this->y >= 600 - this->radius)
        this->y = 0 + this->radius;
}

void Ball::draw()
{
    glColor3f(1, (float)51 / 255, (float)51 / 255);
    glBegin(GL_POLYGON);
    for (int deg = 0; deg <= 360; deg += 1)
        glVertex2i(this->x + (this->radius * cos(deg)), this->y + (this->radius * sin(deg)));

    glEnd();
}