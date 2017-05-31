/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:17:39 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:23:38 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	look_for;
	int		index;
	int		last_index;

	look_for = (char)c;
	index = 0;
	last_index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == look_for)
			last_index = index;
		++index;
	}
	if (look_for == '\0')
		if (s[index] == '\0')
			return ((char *)s + index);
	return ((last_index == 0) ? NULL : (char *)s + last_index);
}
