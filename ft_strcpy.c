/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:16:30 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:14:04 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
