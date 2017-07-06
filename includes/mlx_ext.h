/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ext.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:28:52 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 11:02:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EXT_H
# define MLX_EXT_H

# include "ft_point2d.h"

typedef struct	s_wininfo
{
	void	*mlx;
	void	*win;
}				t_wininfo;

void			draw_rect(t_wininfo *wininfo,
				t_point2d start, t_point2d end, int color);
void			draw_line(t_wininfo *wininfo, t_point2d start, t_point2d end,
				int color);

#endif
