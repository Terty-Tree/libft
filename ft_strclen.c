/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:35:52 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:35:52 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

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
