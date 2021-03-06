/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:48 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/11 15:43:07 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

static void				*mv_from_back(char *dst, const char *src, size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		--n;
	}
	return ((void *)dst);
}

static void				*mv_from_frnt(char *dst, const char *src, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		dst[counter] = src[counter];
		++counter;
	}
	return ((void *)dst);
}

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || dst == src)
		return (dst);
	if (src > dst)
		return (mv_from_frnt((char *)dst, (char *)src, len));
	return (mv_from_back((char *)dst, (char *)src, len));
}
