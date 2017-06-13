#include "libft.h"

t_list	*ft_lstgetr(t_list *lst)
{
	if (lst != NULL)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}
