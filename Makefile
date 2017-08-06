NAME  = libft.a
SRCS  = {ft_atoi,ft_bzero,ft_ischar,ft_ischar2,ft_itoa,ft_lstmanip,ft_put}.c
SRCS += {ft_lstuse,ft_memalloc,ft_memccpy,ft_memchr,ft_memcmp,ft_memcpy}.c
SRCS += {ft_memdel,ft_memmove,ft_memset,ft_strcat,ft_strchr,ft_put_fd}.c
SRCS += {ft_strclen,ft_strclr,ft_strcmp,ft_strcpy,ft_strdel,ft_strdup}.c
SRCS += {ft_striter,ft_strtrim,ft_striteri,ft_strjoin,ft_strlen,ft_strccpy}.c
SRCS += {ft_tolower,ft_toupper,ft_strmap,ft_strmapi,ft_strncpy,ft_strcdup}.c
SRCS += {ft_strcjoin,ft_strnew,ft_strrchr,ft_strsplit,ft_strstr,ft_strsub}.c
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
