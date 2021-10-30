all: main.o game.o
	g++ main.o game.o texturemanager.o -o main -lSDL2 -lSDL2_image
main.o: main.cpp
	g++ -c main.cpp 
game.o: game.h game.cpp
	g++ -c game.cpp
texturemanager.o: texturemanager.h texturemanager.cpp
	g++ -c texturemanager.cpp
clean:
	rm main.o
	rm main
	rm game.o
	rm texturemanager.o