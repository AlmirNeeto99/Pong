#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    int x, y, radius, vx, vy;
    Ball(int x, int y, int radius);
    ~Ball();
    void move(int x, int y);
    void update();
    void draw();
};

#endif