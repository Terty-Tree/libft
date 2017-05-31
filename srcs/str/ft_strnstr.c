/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:24:49 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:23:31 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	int		l_len;

	counter = 0;
	l_len = ft_strlen(little);
	while ((counter + l_len) < len && big[counter] != '\0')
	{
		if (ft_memcmp(little, big, l_len) == 0)
			return ((char *)big + counter);
		++counter;
	}
	return (NULL);
}
