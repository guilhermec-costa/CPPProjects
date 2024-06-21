cmake_minimum_required(VERSION 3.29.0)
# Nome do projeto
project(cppIntro)

set(SOURCE_FILES 
    main.cpp 
    Machine.cpp 
    Pointers.cpp 
    Cat.cpp 
    NS.cpp 
    functions.cpp 
    particle/main.cpp
    particle/window.cpp
    particle/particle.cpp
    particle/particle_orchestrator.cpp
)
# Adicionar o executável
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Encontrar a biblioteca SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Linkar SDL2 ao executável
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
