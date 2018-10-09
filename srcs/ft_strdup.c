/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:17:24 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/31 08:42:36 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ret == NULL)
		return (NULL);
	return (ft_strcpy(ret, s1));
}

char	*ft_strcdup(const char *str, char d)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strclen(str, d))) != NULL)
		ft_strccpy(ret, str, d);
	return (ret);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	min;

	if ((ret = ft_strnew((min = MIN(ft_strlen(str), n)))) != NULL)
		ft_strncpy(ret, str, min + 1);
	return (ret);
}
