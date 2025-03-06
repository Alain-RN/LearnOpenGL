#include "glad.h"
#include <GLFW/glfw3.h> 
#include <iostream>

int main(int, char**) {
    GLFWwindow* window;

    if(!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(600, 400, "Window!", NULL, NULL);

    while( !glfwWindowShouldClose(window) ) {
        glfwPollEvents();

        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}