/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:56:06 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 09:57:10 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point3d.h"

t_point3d	*set_point3d(t_point3d *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_point3d	*cpy_point3d(t_point3d *dst, t_point3d src)
{
	dst->x = src.x;
	dst->y = src.y;
	dst->z = src.z;
	return (dst);
}
