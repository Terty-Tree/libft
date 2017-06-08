/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:32:51 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:32:51 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	counter;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret != NULL)
	{
		counter = 0;
		while (size >= counter)
		{
			ret[counter] = '\0';
			++counter;
		}
	}
	return (ret);
}
