PROJ_NAME = fuckit
SRCDIR = src
BUILDDIR = build

SRC_FILES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/particle/*.cpp) \
	$(wildcard $(SRCDIR)/sdlAPI/*.cpp) $(wildcard $(SRCDIR)/sdlAPI/resource_managers/*.cpp)

INCDIRS = -Isrc -Isrc/particle -Isrc/sdlAPI -IDependencies/SDL2/include

LIB_DIRS = -LDependencies/SDL2/x64

LIBS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf

CXXFLAGS = $(INCDIRS) $(LIB_DIRS) $(LIBS)

DEBUG_FLAGS = -DDEBUG
RELEASE_FLAGS = -O3 -DRELEASE

EXECUTABLE = $(BUILDDIR)/exec.exe
DEBUG_EXECUTABLE = $(BUILDDIR)/$(PROJ_NAME)_debug.exe

default: $(EXECUTABLE)

debug: CXXFLAGS += -g
debug: $(DEBUG_EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
	g++ $(SRC_FILES) -o $(EXECUTABLE) $(CXXFLAGS) $(RELEASE_FLAGS)

$(DEBUG_EXECUTABLE): $(SRC_FILES)
	g++ $(SRC_FILES) -o $(DEBUG_EXECUTABLE) $(CXXFLAGS) $(DEBUG_FLAGS)

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SRCDIR)/*.o
	rm -f $(SRCDIR)/particle/*.o
	rm -f $(SRCDIR)/sdlAPI/*.o
