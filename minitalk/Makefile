C_Compiler = cc
CFLAGS = -Wall -Wextra -Werror


libftprintf = printf/libftprintf.a
LIBS = -Lprintf -lftprintf

all: server client

server: server.c $(libftprintf) minitalk.h
	$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

client: client.c $(libftprintf) minitalk.h
	$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)


$(libftprintf):
	make -C printf

clean:
	rm -f *.o
	make -C printf clean

fclean: clean
	rm -f server client
	make -C printf fclean

re: fclean all

.PHONY: clean 