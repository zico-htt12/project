CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

game: main.o game.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c game.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o game
