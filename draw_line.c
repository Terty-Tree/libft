/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:27:57 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 11:23:22 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "libft.h"
#include "mlx_ext.h"
#include "ft_point2d.h"

#define FT_DA 0
#define FT_SA 1
#define FT_DM 0
#define FT_SM 1

static void	init_mag(t_point2d start, t_point2d end, int *mag)
{
	int	x_mag;
	int	y_mag;

	x_mag = end.x - start.x;
	y_mag = end.y - start.y;
	mag[FT_DA] = MAX(x_mag, y_mag);
	mag[FT_SA] = MIN(x_mag, y_mag);
}

static void init_axes(t_point2d start, t_point2d end, int **axes,
		t_point2d *draw)
{
	int x_mag;
	int y_mag;

	x_mag = end.x - start.x;
	y_mag = end.y - start.y;
	axes[FT_DA] = (y_mag > x_mag) ? &(draw->y) : &(draw->x);
	axes[FT_SA] = (axes[FT_DA] == &(draw->y)) ? &(draw->x) : &(draw->y);
}

#include <stdio.h>
void		draw_line(t_wininfo *wininfo,
			t_point2d start, t_point2d end, int color)
{
	t_point2d	draw;
	int			err;
	int			mag[2];
	int			*axes[2];

	init_mag(start, end, mag);
	init_axes(start, end, axes, &draw);
	cpy_point2d(&draw, start);
	err = mag[FT_SM] - mag[FT_DM];
	while (draw.y != end.y || draw.x != end.x)
	{
		printf("x: %i; y: %i\n", draw.x, draw.y);
		mlx_pixel_put(wininfo->mlx, wininfo->win, draw.x, draw.y, color);
		if (err >= 0)
		{
			*(axes[FT_SA]) += (mag[FT_SM] < 0) ? -1 : 1;
			err -= ABS(mag[FT_SM]);
		}
		*(axes[FT_DA]) += (mag[FT_DM] < 0) ? -1 : 1;
		err += ABS(mag[FT_DM]);
	}
}
