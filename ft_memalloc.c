/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:33:12 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 16:20:14 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;

	ret = (unsigned char *)malloc(size);
	if (ret != NULL)
		while (size > 0)
		{
			ret[size - 1] = 0;
			--size;
		}
	return ((void *)ret);
}
