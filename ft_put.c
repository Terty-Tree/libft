#include <unistd.h>

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (*s != '\0')
		write(1, s, ft_strlen(s));
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	if (n < -9 || n > 9)
		ft_putnbr(ABS(n / 10));
	ft_putchar(ABS(n % 10) + '0');
}
