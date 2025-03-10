#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void framebuffer_size_callback( GLFWwindow* window, int width, int height);

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ma premiere fentre", NULL, NULL);

    if( window == NULL ) {
        cout << "Error: Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) ) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    while(!glfwWindowShouldClose(window)) {
        // glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback( GLFWwindow* window, int width, int height) {
    // std::cout << "Nouvelle taille : " << width << "x" << height << std::endl;
    glViewport(0, 0, width, height);
};

