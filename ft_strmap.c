/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:40:07 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:40:07 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	int		index;

	ret = NULL;
	if (s != NULL && f != NULL)
	{
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ret)
		{
			index = 0;
			while (s[index] != '\0')
			{
				ret[index] = f(s[index]);
				++index;
			}
			ret[index] = '\0';
		}
	}
	return (ret);
}
