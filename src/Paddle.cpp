#include "headers/Paddle.hpp"
#include "headers/Window.hpp"
#include "GL/gl.h"

Paddle::Paddle(int x, int y)
{
    this->x = x;
    this->y = y;
}

Paddle::~Paddle() {}

int Paddle::checkWindowCollision()
{
    if (this->y < 0)
    {
        return this->TOP;
    }

    if (this->y > Window::HEIGHT - this->height)
    {
        return this->BOTTOM;
    }

    return 0;
}

void Paddle::move()
{
    if (this->keyPressed(Key::W))
    {
        this->y -= 5;
    }
    else if (this->keyPressed(Key::S))
    {
        this->y += 5;
    }
}

void Paddle::update()
{
    this->move();
    int whereCollided = this->checkWindowCollision();
    if (whereCollided == this->TOP)
    {
        this->y = 0;
    }
    else if (whereCollided == this->BOTTOM)
    {
        this->y = Window::HEIGHT - this->height;
    }
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