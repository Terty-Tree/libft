/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:19 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 16:09:53 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			counter;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	counter = 0;
	while (counter < n)
	{
		*ptr_dst = *ptr_src;
		if (*ptr_dst == ((unsigned char)c))
			return (++ptr_dst);
		++ptr_dst;
		++ptr_src;
		++counter;
	}
	return (NULL);
}
