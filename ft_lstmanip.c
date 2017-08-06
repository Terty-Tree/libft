#include <stdlib.h>

#include "libft.h"

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		ret->next = NULL;
		ret->content = NULL;
		if (content != NULL)
			if ((ret->content = malloc(content_size)) != NULL)
				ft_memcpy(ret->content, content, content_size);
		ret->content_size = (ret->content == NULL) ? 0 : content_size;
	}
	return (ret);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	*alst = new;
	(*alst)->next = tmp;
}

void	ft_lstaddr(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	if (*alst != NULL)
		free(*alst);
	*alst = NULL;
}

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
