#ifndef PADDLE_H
#define PADDLE_H
#include "listeners/KeyListener.hpp"

class Paddle
    : public KeyListener
{
public:
    int x, y;
    Paddle(int x, int y);
    ~Paddle();
    void update();
    void draw();
    void checkWindowCollision();

private:
    const int width = 15;
    const int height = 150;
};

#endif