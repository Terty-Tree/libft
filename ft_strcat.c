/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:46:37 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:13:40 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int catat;

	index = 0;
	while (s1[index] != '\0')
		++index;
	catat = index;
	while (s2[index - catat] != '\0')
	{
		s1[index] = s2[index - catat];
		++index;
	}
	s1[index] = 0;
	return (s1);
}
