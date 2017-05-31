/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:31:29 by pde-brui          #+#    #+#             */
/*   Updated: 2017/05/31 13:31:29 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	strcpy(ret, s1);
	strcat(ret, s2);
	return (ret);
}
