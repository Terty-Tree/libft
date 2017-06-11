/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:40:21 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/08 13:49:38 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	bgn_index(const char *str)
{
	int start;

	start = 0;
	while (ft_iswhite(str[start]) && str[start] != '\0')
		++start;
	return (start);
}

static int	end_index(int begin, const char *str)
{
	int end;

	end = begin;
	while (str[begin] != '\0')
	{
		if (!ft_iswhite(str[begin]))
			end = begin;
		++begin;
	}
	return (end);
}

static int	trimmed_len(int begin, int end, const char *str)
{
	if (str[end] == '\0')
		return (end - begin);
	return (end - begin + 1);
}

char		*ft_strtrim(const char *s)
{
	char	*ret;
	int		begin;
	int		end;
	int		index;

	ret = NULL;
	if (s != NULL)
	{
		begin = bgn_index(s);
		end = end_index(begin, s);
		index = begin;
		ret = ft_strnew(trimmed_len(begin, end, s));
		if (ret)
		{
			while (index <= end)
			{
				ret[index - begin] = s[index];
				++index;
			}
		}
	}
	return (ret);
}
