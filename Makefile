SOURCES = *.c
OBJECTS = *.o
INCLUDE = -I.

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(INCLUDE) $(SOURCES)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
