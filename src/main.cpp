#include "GL/gl.h"
#include "GLFW/glfw3.h"
#include "headers/Ball.hpp"
#include "headers/Paddle.hpp"
#include "headers/events/KeyEvent.hpp"
// #include "glm/glm.hpp"
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include <cstdio>

void handle_key(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else
    {
        KeyEvent::setEvent(key, scancode, action, mode);
    }
}

void configureView(int width, int heigth)
{
    glViewport(0, 0, width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, heigth, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(.0f, .0f, .0f, .0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char const *argv[])
{
    if (!glfwInit())
    {
        printf("Failed to init  GLFW\n");
        return -1;
    }
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow *window = glfwCreateWindow(1000, 600, "Pong", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create window\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    configureView(1000, 600);
    /* Callbacks */
    glfwSetKeyCallback(window, handle_key);
    /* Callbacks */

    Ball ball = Ball(500, 300, 10);
    Paddle paddleLeft = Paddle(30, 200);
    Paddle paddleRight = Paddle(950, 200);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /* \/ Update \/ */
        ball.update();
        paddleLeft.update();
        paddleRight.update();
        ball.collidedPaddle(&paddleLeft);
        ball.collidedPaddle(&paddleRight);
        /* /\ Update /\ */
        /* \/ Drawing \/ */
        ball.draw();
        paddleLeft.draw();
        paddleRight.draw();
        /* /\ Drawing /\ */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return GLFW_TRUE;
}
