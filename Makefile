all: xchess

xchess: xchess.c
	$(CC) $(CFLAGS) xchess.c -o xchess -lX11

clean:
	rm -f xchess chess_test

chess_test: chess.c chess.h chess_test.c
	$(CC) $(CFLAGS) chess.c chess_test.c -o chess_test
