/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 06:51:46 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/08 06:52:05 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstgetr(t_list *lst)
{
	if (lst != NULL)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}

int		ft_lstlen(t_list *lst)
{
	int len;

	len = 0;
	while (lst != NULL)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

void	ft_lstsimplefree(void *content, size_t content_size)
{
	if (content != NULL && content_size != 0)
		free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (tmp == NULL)
		{
			ft_lstdel(&ret, &ft_lstsimplefree);
			return (ret);
		}
		ft_lstaddr(&ret, f(lst));
		lst = lst->next;
	}
	return (ret);
}
