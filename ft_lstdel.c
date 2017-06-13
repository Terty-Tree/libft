/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:36:49 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/11 15:37:29 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *alst;
	while (cur != NULL)
	{
		nxt = cur->next;
		ft_lstdelone(&cur, del);
		cur = nxt;
	}
	*alst = NULL;
}
