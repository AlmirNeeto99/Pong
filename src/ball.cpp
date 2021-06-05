#include "headers/ball.hpp"
#include "GL/gl.h"

Ball::Ball() {}

Ball::Ball(int x, int y) {}

Ball::~Ball() {}

void Ball::move(int x, int y) {}

void Ball::update() {}

void Ball::draw()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(500, 150);
    glVertex2f(250, 500);
    glVertex2f(750, 500);
    glEnd();
}