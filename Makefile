NAME  = libft.a

# Memory functions srcs
SRCS  = ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c
# String functions srcs
SRCS += ft_strcat.c ft_striter.c ft_strcmp.c ft_strcpy.c ft_strmap.c ft_chrc.c \
		ft_atoi.c ft_itoa.c ft_strjoin.c ft_strsplit.c ft_strlen.c ft_strdup.c \
		ft_strchr.c ft_strnew.c ft_strtrim.c ft_strsub.c ft_strstr.c ft_strset.c
# Put functions srcs
SRCS += ft_put_fd.c ft_put.c
# Character srcs
SRCS += ft_ischar.c ft_ischar2.c ft_tochar.c
# Data structure sources
SRCS += map.c ft_lstuse.c ft_lstmanip.c cp_vec_manip.c cp_vec_use.c
# Get next line
SRCS += get_next_line.c
# Printf
SRCS += ft_printf.c ft_print_func.c ft_print_handle.c ft_print_init.c
# Misc
SRCS += ft_swap.c

SRCD  = $(addprefix srcs/,$(SRCS))

OBJS  = $(SRCS:.c=.o)
INCL  = -Iincludes

CC = gcc
CF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -c $(CF) $(INCL) $(SRCD)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
