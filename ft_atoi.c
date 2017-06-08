/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:52:26 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/08 13:42:06 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ws(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ');
}

static int	is_neg(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		++(*i);
		return (1);
	}
	if (str[*i] == '+')
		++(*i);
	return (0);
}

int			ft_atoi(const char *str)
{
	long long	ret;
	int			neg;
	int			i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	while (is_atoi_ws(str[i]))
		++i;
	neg = is_neg(str, &i);
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0');
		if (ret < 0)
			return ((neg) ? 0 : -1);
		++i;
	}
	return ((neg) ? -ret : ret);
}
