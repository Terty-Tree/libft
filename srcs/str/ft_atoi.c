/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:52:26 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 16:22:00 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		neg;
	int		i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
			|| str[i] == 13 || str[i] == 32)
		++i;
	if ((neg = str[i] == '-'))
		++i;
	else if (str[i] == '+')
		++i;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0');
		++i;
	}
	return ((neg) ? -ret : ret);
}
