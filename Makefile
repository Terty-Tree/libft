SOURCES = srcs/chr/*.c \
		  srcs/lst/*.c \
		  srcs/mem/*.c \
		  srcs/put/*.c \
		  srcs/str/*.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra

TARGET = libft.a

$(TARGET): all

all:
	$(CC) -c $(CFLAGS) -I. $(SOURCES)
	mv *.o out
	ar rc $(TARGET) out/*.o

clean:
	rm -f out/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
