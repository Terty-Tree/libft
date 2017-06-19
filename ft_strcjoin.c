/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:38:14 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/19 11:38:15 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (ret);
}
