/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:39:28 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/06 14:57:09 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_c;
	const char	*src_c;
	size_t		dst_l;

	if (size == 0)
		return (size);
	/* Find end of dst */
	dst_c = dst;
	while ((unsigned long)(dst_c - dst) < size && *dst_c != '\0')
		++dst_c;
	/* Returned size if size has been reached and '\0' has not been found */
	if ((unsigned long)(dst_c - dst) >= size && *dst_c != '\0')
		return (size);
	/* Set dst_l to the length of dst */
	dst_l = dst_c - dst;
	src_c = src;
	while ((unsigned long)(dst_c - dst) < (size - 1) && *src_c != '\0')
	{
		*dst_c = *src_c;
		++dst_c;
		++src_c;
	}
	*dst_c = '\0';
	return (dst_l + (src_c - src) + ft_strlen(src_c));
}
