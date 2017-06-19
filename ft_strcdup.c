/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:38:02 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/19 11:38:04 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strcdup(const char *str, char d)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strclen(str, d))) != NULL)
		ft_strccpy(ret, str, d);
	return (ret);
}
