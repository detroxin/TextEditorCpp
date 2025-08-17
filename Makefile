CC=g++

all:
	$(CC) main.cpp -o main.exe -lncurses -DNCURSES_STATIC