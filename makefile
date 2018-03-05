CC = gcc
CFLAGS = -Wall -w -std=c99 -Iinclude -c -o

main:
		$(CC) $(CFLAGS) bin/carMain.o src/carMain.c
		$(CC) $(CFLAGS) bin/linkedListAPI.o src/linkedListAPI.c
		$(CC) $(CFLAGS) bin/dummy.o src/dummy.c
		$(CC) bin/carMain.o bin/linkedListAPI.o bin/dummy.o -o bin/runMe

test:
		$(CC) $(CFLAGS) bin/testMain.o src/testMain.c
		$(CC) $(CFLAGS) bin/linkedListAPI.o src/linkedListAPI.c
		$(CC) $(CFLAGS) bin/dummy.o src/dummy.c
		$(CC) bin/testMain.o bin/linkedListAPI.o bin/dummy.o -o bin/runMe

clean:
		rm bin/*.o


