/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:44:30 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:44:30 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#define ABS(x) (((x) < 0) ? -x : x)

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= 10)
	{
		ft_putnbr_fd(ABS(n / 10), fd);
		ft_putnbr_fd(ABS(n % 10), fd);
	}
	else
		ft_putchar_fd(ABS(n) + '0', fd);
}
