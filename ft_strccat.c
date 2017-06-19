/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:37:44 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/19 11:37:45 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccat(char *s1, const char *s2, char d)
{
	char		*s1_c;
	const char	*s2_c;

	s1_c = s1;
	s2_c = s2;
	while (*s1_c != '\0')
		++s1_c;
	while (*s2_c != '\0' && *s2_c != d)
	{
		*s1_c = *s2_c;
		++s1_c;
		++s2_c;
	}
	*s1_c = '\0';
	return (s1);
}