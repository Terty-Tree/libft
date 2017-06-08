/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:10 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:09:06 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		*ptr = 0;
		++ptr;
		++counter;
	}
}
