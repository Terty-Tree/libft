/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:32:51 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/09 06:55:23 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if ((ret = (char *)malloc(sizeof(char) * (size + 1)))  != NULL)
	{
		ret[size] = '\0';
		while (size)
		{
			ret[size - 1] = '\0';
			--size;
		}
	}
	return (ret);
}
