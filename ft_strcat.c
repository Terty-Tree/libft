/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:46:37 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:13:40 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int catat;

	index = 0;
	while (s1[index] != '\0')
		++index;
	catat = index;
	while (s2[index - catat] != '\0')
	{
		s1[index] = s2[index - catat];
		++index;
	}
	s1[index] = 0;
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t catat;

	index = 0;
	while (s1[index] != '\0')
		++index;
	catat = index;
	while (s2[index - catat] != '\0' && (index - catat) < n)
	{
		s1[index] = s2[index - catat];
		++index;
	}
	s1[index] = 0;
	return (s1);
}

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

char	*ft_strccat(char *s1, const char *s2, char d)
{
	char		*s1_c;
	const char	*s2_c;

	s1_c = s1;
	s2_c = s2;
	while (*s1_c != '\0')
		++s1_c;
	while (*s2_c != '\0' && *s2_c != d)
	{
		*s1_c = *s2_c;
		++s1_c;
		++s2_c;
	}
	*s1_c = '\0';
	return (s1);
}
