#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    int x, y, radius, vx, vy;
    Ball(int x, int y, int radius);
    ~Ball();
    void onCollision(int x, int y, void (*callback)());
    void update();
    void draw();

private:
    void checkCollision();
};

#endif