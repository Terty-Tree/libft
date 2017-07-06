/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point2d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:44:11 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 09:56:36 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT2D_H
# define FT_POINT2D_H

typedef struct	s_point2d
{
	int	x;
	int	y;
}				t_point2d;

t_point2d	*set_point2d(t_point2d *point, int x, int y);
t_point2d	*cpy_point2d(t_point2d *dst, t_point2d src);

#endif
