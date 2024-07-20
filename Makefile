CC = gcc
flags = -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

run: ./bin/game.exe
	bin/game

all: link compile clean

compile:
	$(CC) -o bin/game obj/*.o $(flags)

link: main game

main: 
	$(CC) -c src/main.c -o obj/main.o

game:
	$(CC) -c src/game.c -o obj/game.o

clean:
	del /q .\obj\*.o


