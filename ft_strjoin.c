/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:31:29 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/02 14:50:23 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (ret != NULL)
		{
			ft_strcpy(ret, s1);
			ft_strcat(ret, s2);
		}
	}
	return (ret);
}
