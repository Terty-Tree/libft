/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:52:26 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/11 12:59:10 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ws(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ');
}

static int	is_neg(const char **str)
{
	if (**str == '-')
	{
		++(*str);
		return (1);
	}
	if (**str == '+')
		++(*str);
	return (0);
}

int			ft_atoi(const char *str)
{
	long	ret;
	long	tmp;
	int		neg;

	while (is_atoi_ws(*str))
		++str;
	neg = is_neg(&str);
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = (ret * 10) + (*str - '0');
		if (tmp / 10 != ret)
			return ((neg) ? 0 : -1);
		ret = tmp;
		++str;
	}
	return ((neg) ? -ret : ret);
}
