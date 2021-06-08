#include "headers/Ball.hpp"

Ball::Ball(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    srand(time(0));
    int direction = rand() % 360;
    this->vx = this->radius * cos(direction);
    this->vy = this->radius * sin(direction);
}

Ball::~Ball() {}

void Ball::checkCollidedLimits()
{
    int nextX = this->x + vx, nextY = this->y + vy;
    if (nextY >= 600 - this->radius || nextY <= 0 + this->radius)
    {
        this->vy *= -1;
    }
    if (nextX >= 1000 - this->radius || nextX <= 0 + this->radius)
    {
        this->vx *= -1;
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
    if (nextX >= paddle->x && nextX <= paddle->x + 20 && nextY >= paddle->y && nextY <= paddle->y + 150)
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