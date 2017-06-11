/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:01 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:23:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n_len;

	if ((n_len = ft_strlen(needle)) == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
