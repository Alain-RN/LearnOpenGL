// #include "glad.h"
// #include <GLFW/glfw3.h> 
// #include <iostream>

// int main(int, char**) {
//     GLFWwindow* window;

//     if(!glfwInit()) {
//         return -1;
//     }

//     window = glfwCreateWindow(600, 400, "Window!", NULL, NULL);

//     while( !glfwWindowShouldClose(window) ) {
//         glfwPollEvents();

//         glfwSwapBuffers(window);

//     }

//     glfwTerminate();
//     return 0;
// }
#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Vertex shader source code
const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
void main() {
    gl_Position = vec4(aPos, 1.0);
}
)";

// Fragment shader source code
const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f); // Bleu
}
)";

int main() {
    // Initialiser GLFW
    if (!glfwInit()) {
        std::cerr << "Erreur d'initialisation de GLFW!" << std::endl;
        return -1;
    }

    // Créer une fenêtre avec OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 3.3 Triangle", nullptr, nullptr);
    if (!window) {
        std::cerr << "Échec de la création de la fenêtre!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialiser GLAD pour gérer les extensions OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Échec du chargement des extensions OpenGL!" << std::endl;
        return -1;
    }

    // Définir les vertices d'un triangle
    float vertices[] = {
        0.0f,  0.5f, 0.0f,  // Haut
       -0.5f, -0.5f, 0.0f,  // Bas gauche
        0.5f, -0.5f, 0.0f   // Bas droit
    };

    // Création d'un VBO (Vertex Buffer Object) et d'un VAO (Vertex Array Object)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Compiler les shaders
    unsigned int vertexShader, fragmentShader, shaderProgram;
    
    // Vertex Shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "Erreur de compilation du shader vertex: " << infoLog << std::endl;
    }

    // Fragment Shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "Erreur de compilation du shader fragment: " << infoLog << std::endl;
    }

    // Shader Program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Erreur de liaison du shader program: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        // Gestion des événements
        glfwPollEvents();

        // Effacer l'écran avec une couleur de fond (noir)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Utiliser le shader program
        glUseProgram(shaderProgram);

        // Dessiner le triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Échanger les buffers (afficher ce qui a été dessiné)
        glfwSwapBuffers(window);
    }

    // Libérer les ressources et terminer
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
