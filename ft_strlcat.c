/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:39:28 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/08 13:38:33 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

static char	*find_end(char *dst, size_t *r)
{
	while (*r > 0 && *dst != '\0')
	{
		--(*r);
		++dst;
	}
	return (dst);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_c;
	const char	*src_c;
	size_t		dst_l;
	size_t		r;

	r = size;
	dst_c = find_end(dst, &r);
	dst_l = dst_c - dst;
	if (r == 0)
		return (size + ft_strlen(src));
	src_c = src;
	while (r > 1 && *src_c != '\0')
	{
		*dst_c = *src_c;
		++dst_c;
		++src_c;
		--r;
	}
	*dst_c = '\0';
	while (*src_c != '\0')
		++src_c;
	return (dst_l + (src_c - src));
}
