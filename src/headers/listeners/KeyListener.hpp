#ifndef KEY_LISTENER_H
#define KEY_LISTENER_H
#include "GLFW/glfw3.h"
enum Keys
{
    W = GLFW_KEY_W,
    S = GLFW_KEY_S
};

class KeyListener
{
private:
public:
    int keyPressed(char key);
    int keyReleased();
};

#endif