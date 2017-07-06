/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:59:06 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 11:22:13 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "mlx_ext.h"

int		main(void)
{
	t_wininfo	wininfo;
	t_point2d	start;
	t_point2d	end;

	wininfo.mlx = mlx_init();
	wininfo.win = mlx_new_window(wininfo.mlx, 500, 500, "test");
	set_point2d(&start, 1, 1);
	set_point2d(&end, 498, 1);
	draw_line(&wininfo, start, end, 0x00FFFFFF);
	set_point2d(&start, 498, 1);
	set_point2d(&end, 498, 498);
	draw_line(&wininfo, start, end, 0x00FFFFFF);
	set_point2d(&start, 498, 498);
	set_point2d(&end, 1, 498);
	draw_line(&wininfo, start, end, 0x00FFFFFF);
	set_point2d(&start, 1, 498);
	set_point2d(&end, 1, 1);
	draw_line(&wininfo, start, end, 0x00FFFFFF);
	mlx_loop(wininfo.mlx);
}
