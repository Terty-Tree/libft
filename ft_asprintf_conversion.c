/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:28:15 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/17 11:35:35 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*convert_num(t_printf *printinfo, va_list ap)
{
	int		strlen;
	char	*ret;
	char	*pad;

	ret = ft_itoa(va_arg(ap, int));
}
