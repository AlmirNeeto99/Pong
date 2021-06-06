#include "headers/events/KeyEvent.hpp"

int KeyEvent::action = 0;
int KeyEvent::mode = 0;
int KeyEvent::key = 0;
int KeyEvent::scancode = 0;

int KeyEvent::getAction()
{
    return action;
}

int KeyEvent::getCode()
{
    return scancode;
}

int KeyEvent::getKey()
{
    return key;
}

int KeyEvent::getMode()
{
    return mode;
}

void KeyEvent::setEvent(int key, int scancode, int action, int mode)
{
    KeyEvent::action = action;
    KeyEvent::key = key;
    KeyEvent::mode = mode;
    KeyEvent::scancode = scancode;
}