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

static void	ft_putnum(unsigned int n)
{
	if (n >= 10)
		ft_putnum(n / 10);
	ft_putchar((n % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_putnum((ABS(n)));
}
