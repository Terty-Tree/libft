/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:37:01 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:37:01 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	ft_freecontent(void *c, size_t c_s)
{
	if (c_s != 0)
		free(c);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (tmp == NULL)
		{
			ft_lstdel(&ret, &ft_freecontent);
			return (ret);
		}
		ft_lstaddr(&ret, f(lst));
		lst = lst->next;
	}
	return (ret);
}
