/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:24:49 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/11 15:46:05 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

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
