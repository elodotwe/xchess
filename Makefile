all: xchess

xchess: xchess.c
	$(CC) $(CFLAGS) xchess.c -o xchess -lX11

clean:
	rm -f xchess
