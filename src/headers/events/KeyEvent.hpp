#ifndef KEY_EVENT_H
#define KEY_EVENT_H

class KeyEvent
{
private:
    static int key, scancode, action, mode;

public:
    static void setEvent(int key, int scancode, int action, int mode);
    static int getKey();
    static int getCode();
    static int getAction();
    static int getMode();
};
#endif