/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:39:28 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:14:17 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	catat;

	index = 0;
	while (index < size && dst[index] != '\0')
		++index;
	catat = index;
	while (index < size && src[index - catat] != '\0')
	{
		dst[index] = src[index - catat];
		++index;
	}
	if (index < size)
	{
		dst[index] = '\0';
		++index;
	}
	return (index);
}
