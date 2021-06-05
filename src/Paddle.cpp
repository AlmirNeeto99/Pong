#include "headers/Paddle.hpp"
#include "GL/gl.h"

Paddle::Paddle(int x, int y)
{
    this->x = x;
    this->y = y;
}

Paddle::~Paddle() {}

void Paddle::update() {}

void Paddle::draw()
{
    glBegin(GL_QUADS);
    glVertex2i(this->x, this->y);
    glVertex2i(this->x + this->width, this->y);
    glVertex2i(this->x + this->width, this->y + this->height);
    glVertex2i(this->x, this->y + this->height);
    glEnd();
}