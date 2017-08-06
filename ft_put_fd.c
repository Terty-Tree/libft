#include <unistd.h>

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (*s != '\0')
		write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(1, "-", 1);
	if (n < -9 || n > 9)
		ft_putnbr_fd(ABS(n / 10), fd);
	ft_putchar_fd(ABS(n % 10) + '0', fd);
}
