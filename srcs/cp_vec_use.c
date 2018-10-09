/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_vec_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:40:16 by pde-brui          #+#    #+#             */
/*   Updated: 2017/09/19 15:17:28 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cp_vec.h"
#include "libft.h"

t_cp_vec	*cp_vec_add(t_cp_vec *vec, char *val)
{
	t_cp_vec	*tmp;

	if (vec == NULL)
		vec = cp_vec_new(1);
	if (vec->size + 1 > vec->capacity)
	{
		tmp = vec;
		vec = cp_vec_new(tmp->capacity + 1);
		vec = cp_vec_cpy(vec, tmp);
		cp_vec_free(&tmp);
	}
	vec->vals[vec->size] = ft_strdup(val);
	vec->size += 1;
	return (vec);
}

t_cp_vec	*cp_vec_rm(t_cp_vec *vec, int index)
{
	t_cp_vec	*tmp;
	char		*val;

	if (vec == NULL || index < 0 || index >= vec->size)
		return (vec);
	if ((val = cp_vec_get(vec, index)) != NULL)
		free(val);
	while (index + 1 < vec->size)
	{
		vec->vals[index] = vec->vals[index + 1];
		++index;
	}
	if ((vec->size -= 1) < (int)(vec->capacity * LOAD_FACTOR))
	{
		tmp = cp_vec_new(vec->capacity * LOAD_FACTOR);
		tmp = cp_vec_cpy(tmp, vec);
		cp_vec_free(&vec);
		vec = tmp;
	}
	return (vec);
}

t_cp_vec	*cp_vec_sort(t_cp_vec *vec, int (*cmp)(const char *, const char *))
{
	int		sorted;
	int		index;
	int		max;
	int		res;

	if (vec == NULL)
		return (vec);
	sorted = 0;
	max = vec->size;
	while (!sorted)
	{
		sorted = 1;
		index = 0;
		while (index < max - 1)
		{
			if ((res = cmp(vec->vals[index], vec->vals[index + 1])) > 0)
			{
				sorted = 0;
				ft_cpswap(&(vec->vals[index]), &(vec->vals[index + 1]));
			}
			++index;
		}
		--max;
	}
	return (vec);
}

char		*cp_vec_get(t_cp_vec *vec, int index)
{
	if (vec == NULL || index < 0 || index >= vec->size)
		return (NULL);
	return (vec->vals[index]);
}

char		**cp_vec_to_tab(t_cp_vec *vec)
{
	char	**ret;
	int		i;

	if (vec == NULL)
		return (NULL);
	if ((ret = (char **)malloc(sizeof(char *) * (vec->size + 1))) != NULL)
	{
		i = 0;
		while (i < vec->size)
		{
			ret[i] = ft_strdup(cp_vec_get(vec, i));
			++i;
		}
		ret[i] = NULL;
	}
	return (ret);
}
