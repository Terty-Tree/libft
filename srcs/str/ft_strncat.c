/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:45:28 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:15:19 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t catat;

	index = 0;
	while (s1[index] != '\0')
		++index;
	catat = index;
	while (s2[index - catat] != '\0' && (index - catat) < n)
	{
		s1[index] = s2[index - catat];
		++index;
	}
	s1[index] = 0;
	return (s1);
}
