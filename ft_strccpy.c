

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char d)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && src[index] != d)
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
