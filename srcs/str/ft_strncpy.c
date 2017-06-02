/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:46:28 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/02 15:18:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dst[index] = src[index];
		++index;
	}
	while (index < len)
	{
		dst[index] = '\0';
		++index;
	}
	return (dst);
}
