/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:16:23 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:13:26 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = (unsigned char *)b;
	counter = 0;
	while (counter < len)
	{
		*ptr = c;
		++counter;
		++ptr;
	}
	return (b);
}
