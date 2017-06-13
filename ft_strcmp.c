/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:32:27 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/11 16:03:06 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strcmp(const char *s1, const char *s2)
{
	int	counter;

	counter = 0;
	while (s1[counter] != '\0' || s2[counter] != '\0')
	{
		if (s1[counter] != s2[counter])
		{
			return (((unsigned char)s1[counter]) -
					((unsigned char)s2[counter]));
		}
		++counter;
	}
	return (0);
}
