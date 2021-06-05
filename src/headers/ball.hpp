#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    int x;
    int y;
    Ball();
    Ball(int x, int y);
    ~Ball();
    void move(int x, int y);
    void update();
    void draw();
};

#endif