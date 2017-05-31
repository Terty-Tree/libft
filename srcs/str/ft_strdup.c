/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:17:24 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/30 09:14:10 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret;

	ret = (char *)malloc(ft_strlen(s1));
	if (ret == NULL)
		return (NULL);
	return (ft_strcpy(ret, s1));
}
