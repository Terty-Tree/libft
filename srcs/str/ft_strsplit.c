/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:32:37 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/02 14:50:51 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int wc;

	wc = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0' && *s != c)
		{
			wc += 1;
			while (*s != '\0' && *s != c)
				++s;
		}
	}
	return (wc);
}

static char	*get_word(const char **s_ori, char c)
{
	const char	*s;
	char		*ret;
	int			index;
	int			w_len;

	while (**s_ori == c && **s_ori != '\0')
		++*s_ori;
	s = *s_ori;
	w_len = ft_strclen(s, c);
	if (w_len == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (w_len + 1));
	index = 0;
	if (ret)
	{
		while (s[index] != c && s[index] != '\0')
		{
			ret[index] = s[index];
			++index;
		}
		ret[index] = '\0';
	}
	*s_ori += index;
	return (ret);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		wc;
	int		counter;

	wc = word_count(s, c);
	ret = (char	**)malloc(sizeof(char *) * (wc + 1));
	if (ret)
	{
		counter = 0;
		while (counter < (wc + 1))
		{
			*(ret + counter) = NULL;
			++counter;
		}
		counter = 0;
		while (*s != '\0')
		{
			ret[counter] = get_word(&s, c);
			++counter;
		}
	}
	return (ret);
}
