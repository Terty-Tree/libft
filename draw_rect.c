/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:28:33 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 09:28:38 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "mlx_ext.h"

void	draw_rect(t_wininfo *wininfo, t_point2d start, t_point2d end, int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			mlx_pixel_put(wininfo->mlx, wininfo->win, x, y, color);
			++x;
		}
		++y;
	}
}
