/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 08:54:22 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 12:08:22 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*printf_handle_num(const char *fmt, t_printf *printinfo)
{
	printinfo->width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		++fmt;
	return (fmt);
}

const char	*printf_handle_flags(const char *fmt, t_printf *printinfo)
{
	printinfo->flags |= *fmt == '-' ? FLAG_LEFT_JUST : 0;
	return (fmt + 1);
}
