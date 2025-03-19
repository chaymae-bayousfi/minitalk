CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_print_char.c ft_print_nbr.c ft_print_ptr.c ft_print_str.c ft_print_u_nbr.c ft_print_x_nbr.c ft_printf.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean