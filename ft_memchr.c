/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:26 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 16:10:25 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	size_t			counter;

	ptr_s = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (*ptr_s == ((unsigned char)c))
			return ((void *)ptr_s);
		++ptr_s;
		++counter;
	}
	return (NULL);
}
