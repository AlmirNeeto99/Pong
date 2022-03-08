#include "headers/Ball.hpp"
#include "headers/Window.hpp"
#include <iostream>

Ball::Ball(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->calculateDirection();
}

Ball::~Ball() {}

void Ball::checkCollidedLimits()
{
    int nextX = this->x + vx, nextY = this->y + vy;
    if (nextY >= Window::HEIGHT - this->radius || nextY <= 0 + this->radius)
    {
        this->vy *= -1;
    }
    if (nextX >= Window::WIDTH - this->radius || nextX <= 0 + this->radius)
    {
        this->vx *= -1;
        if (nextX >= Window::WIDTH - this->radius)
        {
            std::cout << "Player 1 goal" << std::endl;
            this->center();
        }
        else if (nextX <= 0 + this->radius)
        {
            std::cout << "Player 2 goal" << std::endl;
            this->center();
        }
    }
}

void Ball::checkCollisions()
{
    this->checkCollidedLimits();
}

void Ball::changeDirection()
{
    this->vx *= -1;
}

void Ball::collidedPaddle(Paddle *paddle)
{
    int nextX = this->x + this->vx, nextY = this->y + this->vy;
    if (nextX >= paddle->x - this->radius &&
        nextX <= paddle->x + paddle->width + this->radius &&
        nextY >= paddle->y &&
        nextY <= paddle->y + paddle->height)
    {
        this->changeDirection();
    }
}

void Ball::update()
{
    this->checkCollisions();
    this->x += vx;
    this->y += vy;
}

void Ball::draw()
{
    glColor3f(1, (float)51 / 255, (float)51 / 255);
    glBegin(GL_POLYGON);
    for (int deg = 0; deg <= 360; deg += 1)
        glVertex2i(this->x + (this->radius * cos(deg)), this->y + (this->radius * sin(deg)));

    glEnd();
}

void Ball::calculateDirection()
{
    srand(time(0));
    int direction = rand() % 360;
    this->vx = this->radius * cos(direction);
    this->vy = this->radius * sin(direction);
}

void Ball::center()
{
    this->x = Window::WIDTH / 2;
    this->y = Window::HEIGHT / 2;
    this->calculateDirection();
}