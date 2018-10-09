/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:01 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/20 14:23:19 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n_len;

	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ctr;
	size_t	l_len;

	ctr = 0;
	if ((l_len = ft_strlen(little)) == 0)
		return ((char *)big);
	while (ctr < len && big[ctr] != '\0')
	{
		if (len - ctr < l_len)
			return (NULL);
		if (ft_memcmp(little, (big + ctr), MIN(l_len, (len - ctr))) == 0)
			return ((char *)big + ctr);
		++ctr;
	}
	return (NULL);
}
