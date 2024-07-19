CC = gcc
flags = -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

run: ./bin/game.exe
	bin/game

all: link compile clean

compile:
	$(CC) -o bin/game obj/*.o $(flags)

link: main 

main: 
	$(CC) -c src/main.c -o obj/main.o

clean:
	del /q .\obj\*.o


