#ifndef PADDLE_H
#define PADDLE_H
#include "listeners/KeyListener.hpp"

class Paddle
    : public KeyListener
{
public:
    int x, y;
    const int width = 15;
    const int height = 150;
    Paddle(int x, int y);
    ~Paddle();
    void update();
    void draw();

private:
    void move();
    int checkWindowCollision();
    const int TOP = -1;
    const int BOTTOM = 1;
};

#endif