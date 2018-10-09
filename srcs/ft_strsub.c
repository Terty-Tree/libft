/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:40:17 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 07:17:04 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s != NULL)
	{
		if ((ret = ft_strnew(len)) != NULL)
		{
			ret[len] = '\0';
			while (len > 0)
			{
				ret[len - 1] = s[start + (len - 1)];
				--len;
			}
		}
	}
	return (ret);
}
