/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 07:27:12 by pde-brui          #+#    #+#             */
/*   Updated: 2017/09/19 14:14:11 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cp_vec.h"
#include "libft.h"

t_cp_vec	*cp_vec_new(int size)
{
	t_cp_vec	*ret;

	if ((ret = (t_cp_vec *)malloc(sizeof(t_cp_vec))) != NULL)
	{
		ret->vals = (char **)malloc(sizeof(char *) * size);
		ret->size = 0;
		ret->capacity = ret->vals == NULL ? 0 : size;
	}
	return (ret);
}

t_cp_vec	*cp_vec_create(char **tab)
{
	t_cp_vec	*ret;
	char		**tab_c;

	if ((tab_c = tab) == NULL)
		return (NULL);
	while (*tab_c != NULL)
		++tab_c;
	ret = cp_vec_new(tab_c - tab);
	tab_c = tab;
	while (*tab_c != NULL)
	{
		ret = cp_vec_add(ret, *tab_c);
		++tab_c;
	}
	return (ret);
}

t_cp_vec	*cp_vec_cpy(t_cp_vec *dst, t_cp_vec *src)
{
	int		i;

	if (dst == NULL && src != NULL)
		dst = cp_vec_new(src->capacity);
	if (dst != NULL && src != NULL)
	{
		dst->size = 0;
		i = 0;
		while (i < src->size && i < dst->capacity)
		{
			dst->vals[i] = ft_strdup(src->vals[i]);
			dst->size += 1;
			++i;
		}
	}
	return (dst);
}

void		cp_vec_free(t_cp_vec **vec)
{
	t_cp_vec	*vec_c;
	int			i;

	if (vec != NULL && (vec_c = *vec) != NULL)
	{
		i = 0;
		while (i < vec_c->size)
		{
			free(vec_c->vals[i]);
			++i;
		}
		free(vec_c->vals);
		free(vec_c);
		*vec = NULL;
	}
}
