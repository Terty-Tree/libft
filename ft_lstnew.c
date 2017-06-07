/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:37:06 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:37:06 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static t_list	*init_content(t_list **lst, const void *c, size_t c_size)
{
	if (c == NULL)
	{
		(*lst)->content = NULL;
		(*lst)->content_size = 0;
	}
	else
	{
		if (((*lst)->content = malloc(c_size)) == NULL)
		{
			free(*lst);
			return (NULL);
		}
		ft_memcpy((*lst)->content, c, c_size);
		(*lst)->content_size = c_size;
	}
	return (*lst);
}

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		init_content(&ret, content, content_size);
		if (ret != NULL)
			ret->next = NULL;
	}
	return (ret);
}
