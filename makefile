
CC=g++
CPPFLAGS=-Wall -Wextra -pedantic -ansi -O2 -std=c++11 -lSDL2 

ddr-but-you-have-be-on-beat-and-everything: obj/main.o obj/music.o obj/game.o
	$(CC) obj/main.o obj/music.o obj/game.o -o ddr-but-you-have-to-be-on-beat-and-everything $(CPPFLAGS)

obj/main.o: src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o $(CPPFLAGS)

obj/game.o: src/game.cpp
	$(CC) -c src/game.cpp -o obj/game.o $(CPPFLAGS)

obj/music.o: src/music.cpp
	$(CC) -c src/music.cpp -o obj/music.o $(CPPFLAGS)

clean:
	rm obj/*.o ddr-but-you-have-to-be-on-beat-and-everything
