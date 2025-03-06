# cmake_minimum_required(VERSION 3.10)
# project(first_game VERSION 0.1.0)
# cmake_policy(SET CMP0072 NEW)

# set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

# find_package(OpenGL REQUIRED)
# # find_package(GLFW3 REQUIRED)

# add_executable(
#         first_game 
#         src/main.cpp
#         src/glad.h 
#         src/glad.c
# )

# target_link_libraries( 
#         first_game 
#         glfw 
#         OpenGL::GL
# )

cmake_minimum_required(VERSION 3.10)
project(FirstGame)
cmake_policy(SET CMP0072 NEW)

# Spécifie le répertoire où CMake doit chercher GLFW (si nécessaire)
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/GLFW")

# Trouver OpenGL
find_package(OpenGL REQUIRED)


# Ajouter les répertoires d'inclusion
include_directories(include)

# Créer l'exécutable avec les fichiers sources nécessaires
add_executable(
    first_game
    src/main.cpp
    src/glad.c   # Inclure le fichier source GLAD
)

# Lier GLFW, OpenGL et GLAD
target_link_libraries(
    first_game
    glfw
    OpenGL::GL
)
