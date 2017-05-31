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
	char *ret;

	ret = (char *)malloc(sizeof(char) * size);
	if (ret != NULL)
		while (size > 0)
		{
			ret[size - 1] = '\0';
			--size;
		}
	return (ret);
}
