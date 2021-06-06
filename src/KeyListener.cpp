#include "headers/listeners/KeyListener.hpp"
#include "headers/events/KeyEvent.hpp"
#include "GLFW/glfw3.h"

int KeyListener::keyPressed(char k)
{
    int action = KeyEvent::getAction();
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        return KeyEvent::getKey() == k;
    }
}
int KeyListener::keyReleased()
{
    return GLFW_FALSE;
}