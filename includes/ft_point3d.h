/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:16:24 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 09:56:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT3D_H
# define FT_POINT3D_H

typedef struct	s_point3d
{
	double x;
	double y;
	double z;
}				t_point3d;

t_point3d	*set_point3d(t_point3d *point, double x, double y, double z);
t_point3d	*cpy_point3d(t_point3d *dst, t_point3d src);

#endif
