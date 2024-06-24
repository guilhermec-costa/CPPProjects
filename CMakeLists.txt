cmake_minimum_required(VERSION 3.29.0)

project(cppIntro)

# Incluir todos os arquivos .cpp no diretório de fontes e subdiretórios
set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

# Adicionar o executável
add_executable(${PROJECT_NAME} ${source_files})

# Encontrar a biblioteca SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Se find_package(SDL2_image REQUIRED) falhar, defina manualmente
# include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Definir manualmente os diretórios de inclusão e as bibliotecas se necessário
include_directories(/usr/include/SDL2)
link_directories(/usr/lib)

# Linkar SDL2 e SDL2_image ao executável
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
