/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:16:13 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:15:09 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

size_t	ft_strclen(const char *s, int c)
{
	size_t	len;
	char	delim;

	len = 0;
	delim = (char)c;
	while (s[len] != '\0' && s[len] != delim)
		++len;
	return (len);
}
