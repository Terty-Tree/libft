/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:01:50 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 13:23:27 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "map.h"
#include "libft.h"

void	init_printf(t_printf *printinfo, char clearbuff)
{
	printinfo->flags = 0;
	printinfo->width = 0;
	printinfo->modifier = 0;
	if (clearbuff)
		printinfo->buff = NULL;
}

t_map	*init_func_map(void)
{
	t_map	*map;

	map = create_map();
	map_add_val(map, "d", (void *)&printf_num);
	map_add_val(map, "s", (void *)&printf_str);
	map_add_val(map, "c", (void *)&printf_chr);
	return (map);
}
