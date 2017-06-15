/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:38:31 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/15 11:38:34 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char d)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && src[index] != d)
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
