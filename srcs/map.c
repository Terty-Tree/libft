/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 08:59:10 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/08 11:34:18 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "map.h"

t_map			*create_map(int capacity)
{
	t_map	*ret;

	if ((ret = (t_map *)malloc(sizeof(t_map))) != NULL)
	{
		ret->vals = (void **)malloc(sizeof(void *) * capacity);
		if (ret->vals != NULL)
			ret->keys = (char **)malloc(sizeof(char *) * capacity);
		else
			ret->keys = NULL;
		ret->size = 0;
		if (ret->keys == NULL && ret->vals != NULL)
		{
			free(ret->vals);
			ret->vals = NULL;
		}
		ret->capacity = (ret->vals == NULL) ? 0 : capacity;
	}
	return (ret);
}

static t_map	*grow_map(t_map *map)
{
	t_map	*ret;

	if (map == NULL)
		return (create_map(1));
	else
	{
		if ((ret = create_map(map->capacity + 1)) != NULL)
		{
			ft_memcpy(ret->vals, map->vals, map->size * sizeof(void **));
			ft_memcpy(ret->keys, map->keys, map->size * sizeof(char **));
			ret->size = map->size;
			ret->capacity = map->capacity + 1;
		}
		free(map->vals);
		free(map->keys);
		free(map);
	}
	return (ret);
}

t_map			*map_add_val(t_map *map, char *key, void *val)
{
	if (map == NULL)
		map = create_map(1);
	if (map_get_val(map, key) == NULL)
	{
		map->size += 1;
		while (map->size > map->capacity)
			map = grow_map(map);
		map->vals[map->size - 1] = val;
		map->keys[map->size - 1] = key;
	}
	return (map);
}

void			*map_get_val(t_map *map, char *key)
{
	int		index;

	index = 0;
	while (index < map->size)
	{
		if (ft_strcmp(map->keys[index], key) == 0)
			return (map->vals[index]);
		++index;
	}
	return (NULL);
}
