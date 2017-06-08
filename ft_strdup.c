/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:17:24 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/02 17:58:15 by pde-brui         ###   ########.fr       */
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
