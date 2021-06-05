#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
public:
    int x, y;
    Paddle(int x, int y);
    ~Paddle();
    void update();
    void draw();

private:
    const int width = 15;
    const int height = 150;
};

#endif