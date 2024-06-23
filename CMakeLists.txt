cmake_minimum_required(VERSION 3.29.0)

project(cppIntro)

set(source_dir "${PROJECT_SOURCE_DIR}")
file (GLOB root_source_files "${source_dir}/src/*.cpp")
file (GLOB sub_source_files "${source_dir}/src/**/*.cpp")
# Adicionar o executável
add_executable(${PROJECT_NAME} ${root_source_files} ${sub_source_files}) 

# Encontrar a biblioteca SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Linkar SDL2 ao executável
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
