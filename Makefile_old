.PHONY : clean all

CXX:=g++
CXXFLAGS:=-lSDL2 -lSDL2_image
#CPPFILES = src/main.cpp src/game.cpp src/texturemanager.cpp
CPPFILES := $(wildcard src/*.cpp)

OUTPUT = ./output

SOURCE_DIRS := $(dir $(CPPFILES))

VPATH = $(sort $(SOURCE_DIRS))

CPP_FILENAMES := $(notdir $(CPPFILES))

OBJ_FILES := $(patsubst %.cpp, $(OUTPUT)/%.o, $(CPP_FILENAMES) )

all : $(OUTPUT)/program

$(OUTPUT)/program : $(OBJ_FILES)
	g++ $(CXXFLAGS) -o $@ $^

$(OUTPUT)/%.o : %.cpp
	$(shell mkdir -p $(OUTPUT) )
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf output/
run:
	./output/program