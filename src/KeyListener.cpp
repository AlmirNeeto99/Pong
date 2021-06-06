#include "headers/listeners/KeyListener.hpp"
#include "headers/events/KeyEvent.hpp"
#include "GLFW/glfw3.h"

int KeyListener::keyPressed(Key key)
{
    int action = KeyEvent::getAction();
    /* If the key was PRESSED or HELD */
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        /* I used ternary here to be sure the return will be 0 or 1 */
        return KeyEvent::getKey() == key ? GLFW_TRUE : GLFW_FALSE;
    }
    return GLFW_FALSE;
}
int KeyListener::keyReleased()
{
    return GLFW_FALSE;
}