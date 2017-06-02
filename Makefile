SOURCES = srcs/chr/*.c \
		  srcs/lst/*.c \
		  srcs/mem/*.c \
		  srcs/put/*.c \
		  srcs/str/*.c
INCLUDE = includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) -I$(INCLUDE) $(SOURCES)
	mv *.o out
	ar rc $(NAME) out/*.o

clean:
	rm -f out/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
