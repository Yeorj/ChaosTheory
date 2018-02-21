CC = gcc
FLAGS = -O3 -Wall -g

chaos: chaos.c
	$(CC) $(FLAGS) -o chaos chaos.c

clean:
	-del chaos.exe
	-del *.o
	-cls