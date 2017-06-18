#include <stdlib.h>

#include "libft.h"

char	*ft_strcdup(const char *str, char d)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strclen(str, d))) != NULL)
		ft_strccpy(ret, str, d);
	return (ret);
}
