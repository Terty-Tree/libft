/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:50:29 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 15:50:29 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#define ABS(x) (((x) < 0) ? -x : x)

int		num_len(int n)
{
	if (n > 10 || n < -10)
		return (1 + num_len(n / 10));
	else
		return (1);
}

char	*assign(char *val, int n)
{
	if (n > 10 || n < -10)
	{
		val = assign(val, n / 10);
		*val = ABS(n % 10) + '0';
	}
	else
		*val = ABS(n) + '0';
	return (val + 1);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		neg;

	neg = (n < 0);
	ret = (char *)malloc(sizeof(char) * (num_len(n) + neg));
	if (ret)
	{
		if (neg)
		{
			*ret = '-';
			assign(ret + 1, n);
		}
		else
		{
			assign(ret, n);
		}
	}
	return (ret);
}
