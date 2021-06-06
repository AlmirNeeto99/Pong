#ifndef KEY_LISTENER_H
#define KEY_LISTENER_H

#include "GLFW/glfw3.h"

enum Key
{
    W = GLFW_KEY_W,
    S = GLFW_KEY_S,
    SPACE = GLFW_KEY_SPACE
};

class KeyListener
{
private:
public:
    int keyPressed(Key key);
    int keyReleased();
};

#endif