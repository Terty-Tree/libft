/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:31:29 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/09 07:06:49 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		if ((ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
		{
				ft_strcpy(ret, s1);
				ft_strcat(ret, s2);
		}
	}
	else if (s1 != NULL)
		ret = ft_strdup(s1);
	else if (s2 != NULL)
		ret = ft_strdup(s2);
	return (ret);
}

char	*ft_strcjoin(const char *s1, const char *s2, char d)
{
	char	*ret;

	ret = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		if ((ret = ft_strnew(ft_strlen(s1) + ft_strclen(s2, d))) != NULL)
		{
			ft_strcpy(ret, s1);
			ft_strccat(ret, s2, d);
		}
	}
	else if (s1 != NULL)
		return (ft_strdup(s1));
	else if (s2 != NULL)
		return (ft_strcdup(s2, d));
	return (ret);
}
