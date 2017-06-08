/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:35:45 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:09:51 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		++ptr_dst;
		++ptr_src;
		++counter;
	}
	return (dst);
}
