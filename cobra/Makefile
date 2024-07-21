PROJECT_NAME = cobra

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Arquivos de origem
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/components/*.cpp) $(wildcard $(SRC_DIR)/entitites/*.cpp)

# Diretórios de inclusão
INCLUDE_DIRS = -IDependencies/SDL2/include -Iinclude -Isrc/entitites

# Diretórios de bibliotecas
LIB_DIRS = -LDependencies/SDL2/x64

# Bibliotecas
LIBS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lmingw32

# Nome do executável
EXECUTABLE = $(BUILD_DIR)/$(PROJECT_NAME).exe

# Alvo padrão
default: $(EXECUTABLE)

# Regra para criar o executável
$(EXECUTABLE): $(SRC_FILES)
	g++ $(SRC_FILES) -o $(EXECUTABLE) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)

