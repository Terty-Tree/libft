/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 08:59:10 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/08 09:29:06 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "map.h"

static t_map	*grow_map(t_map *map)
{
	void	**vals;
	char	*keys;

	if ((vals = (void **)malloc(sizeof(void *) * (map->capacity + 1))) != NULL)
	{
		if ((keys = (char *)malloc(sizeof(char) * (map->capacity + 1))) != NULL)
		{
			ft_memcpy(vals, map->vals, sizeof(void *) * map->capacity);
			ft_memcpy(keys, map->keys, sizeof(void *) * map->capacity);
			vals[map->capacity] = NULL;
			keys[map->capacity] = 0;
			if (map->vals != NULL)
				free(map->vals);
			if (map->keys != NULL)
				free(map->keys);
			map->vals = vals;
			map->keys = keys;
			map->capacity += 1;
		}
		else
			free(vals);
	}
	return (map);
}

t_map			*create_map(void)
{
	t_map	*ret;

	if ((ret = (t_map *)malloc(sizeof(t_map))) != NULL)
	{
		ret->vals = NULL;
		ret->keys = NULL;
		ret->size = 0;
		ret->capacity = 0;
	}
	return (ret);
}

t_map			*add_val(t_map *map, char key, void *val)
{
	if (get_val(map, key) == NULL)
	{
		map->size += 1;
		while (map->size > map->capacity)
			grow_map(map);
		map->vals[map->size - 1] = val;
		map->keys[map->size - 1] = key;
	}
	return (map);
}

void			*get_val(t_map *map, char key)
{
	int		index;

	index = 0;
	while (index < map->size)
	{
		if (map->keys[index] == key)
			return (map->vals[index]);
		++index;
	}
	return (NULL);
}
