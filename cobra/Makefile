PROJECT_NAME = cobra

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Arquivos de origem
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/components/*.cpp) $(wildcard $(SRC_DIR)/entitites/*.cpp) $(wildcard Dependencies/ImGUI/*.cpp)

# Diretórios de inclusão
INCLUDE_DIRS = -IDependencies/SDL2/include -Iinclude -Isrc/entitites -IDependencies/ImGUI/include/ImGUI -IDependencies/SDL2/include/SDL2

# Diretórios de bibliotecas
LIB_DIRS = -LDependencies/SDL2/x64

# Bibliotecas
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lmingw32

# Flags de compilação
# Flags para build padrão (release)
CXXFLAGS_RELEASE = $(INCLUDE_DIRS) -O2

# Flags para build de debug
CXXFLAGS_DEBUG = $(INCLUDE_DIRS) -g -O0

# Nome do executável
EXECUTABLE = $(BUILD_DIR)/$(PROJECT_NAME).exe

# Alvo padrão
all: default

# Alvo para build padrão (release)
default: CXXFLAGS = $(CXXFLAGS_RELEASE)
default: $(EXECUTABLE)

# Alvo para build de debug
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(EXECUTABLE)

# Regra para criar o executável
$(EXECUTABLE): $(SRC_FILES)
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	g++ $(SRC_FILES) -o $(EXECUTABLE) $(CXXFLAGS) $(LIB_DIRS) $(LIBS)

# Limpeza dos arquivos gerados
clean:
	if exist $(BUILD_DIR) (
		for /r $(BUILD_DIR) %%f in (*) do @if not "%%~xf"==".dll" del "%%f"
		for /d /r $(BUILD_DIR) %%d in (.) do @if not "%%~nxd"=="build" rd /s /q "%%d"
	)
