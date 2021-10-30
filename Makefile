all: main.o game.o
	g++ main.o game.o -o main -lSDL2
main.o: main.cpp
	g++ -c main.cpp -lSDL2
game.o: game.h game.cpp
	g++ -c game.cpp -lSDL2
clean:
	rm main.o
	rm main
	rm game.o