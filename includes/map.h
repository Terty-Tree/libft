/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 07:02:42 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/08 11:34:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	void	**vals;
	char	**keys;
	int		size;
	int		capacity;
}				t_map;

t_map			*create_map();
t_map			*map_add_val(t_map *map, char *key, void *val);
void			*map_get_val(t_map *map, char *key);

#endif
