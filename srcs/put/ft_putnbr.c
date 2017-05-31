/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:44:25 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:44:25 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#define ABS(x) (((x) < 0) ? -x : x)

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n >= 10)
	{
		ft_putnbr(ABS(n / 10));
		ft_putnbr(ABS(n % 10));
	}
	else
		ft_putchar(ABS(n) + '0');
}
