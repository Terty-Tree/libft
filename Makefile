NAME  = libft.a

MEM_SRCS = ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		   ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c
STR_SRCS = ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strsplit.c \
		   ft_striter.c ft_strtrim.c ft_strjoin.c ft_strlen.c ft_strmap.c \
		   ft_atoi.c ft_itoa.c ft_strnew.c ft_strsub.c ft_strstr.c ft_strdup.c \
		   ft_chrc.c
PUT_SRCS = ft_put_fd.c ft_put.c
LST_SRCS = ft_lstuse.c ft_lstmanip.c
CHR_SRCS = ft_ischar.c ft_ischar2.c ft_tochar.c 


SRCS  = $(MEM_SRCS) $(STR_SRCS) $(PUT_SRCS) $(LST_SRCS) $(CHR_SRCS)
OBJS  = $(SRCS:.c=.o)
INCL  = -Iincludes

CC = gcc
CF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -c $(CF) $(INCL) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
