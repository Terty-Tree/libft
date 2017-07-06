/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:52:50 by pde-brui          #+#    #+#             */
/*   Updated: 2017/07/06 10:58:23 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point2d.h"

t_point2d	*set_point2d(t_point2d *point, int x, int y)
{
	point->x = x;
	point->y = y;
	return (point);
}

t_point2d	*cpy_point2d(t_point2d *dst, t_point2d src)
{
	dst->x = src.x;
	dst->y = src.y;
	return (dst);
}
