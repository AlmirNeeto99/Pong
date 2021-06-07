#include "headers/Paddle.hpp"
#include "GL/gl.h"

Paddle::Paddle(int x, int y)
{
    this->x = x;
    this->y = y;
}

Paddle::~Paddle() {}

void Paddle::checkWindowCollision()
{
    if (this->keyPressed(Key::W))
    {
        this->y -= 5;
        /* If reaches the top, stop */
        if (this->y < 0)
        {
            this->y = 0;
        }
    }
    else if (this->keyPressed(Key::S))
    {
        this->y += 5;
        /* If reaches the bottom, stop */
        if (this->y > 600 - this->height)
        {
            this->y = 600 - this->height;
        }
    }
}

void Paddle::update()
{
    this->checkWindowCollision();
}

void Paddle::draw()
{
    glColor3f((float)133 / 255, (float)51 / 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(this->x, this->y);
    glVertex2i(this->x + this->width, this->y);
    glVertex2i(this->x + this->width, this->y + this->height);
    glVertex2i(this->x, this->y + this->height);
    glEnd();
}