/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 06:57:15 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/09 07:15:07 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strset(char **oldstr, char *newstr)
{
	if (oldstr != NULL)
		free(*oldstr);
	return ((*oldstr = newstr));
}
