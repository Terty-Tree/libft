/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:40:09 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/02 17:51:49 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ret[index] = f(index, s[index]);
			++index;
		}
		ret[index] = '\0';
	}
	return (ret);
}
