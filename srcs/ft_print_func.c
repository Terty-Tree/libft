/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 08:18:11 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 08:37:00 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

void			printf_num(t_printf *printinfo, va_list list)
{
	int		num;
	char	*str;
	char	*pad;
	char	num_len;

	num = va_arg(list, int);
	if ((str = ft_itoa(num)) != NULL)
	{
		if ((num_len = ft_strlen(str)) < printinfo->width)
		{
			pad = ft_strnew(printinfo->width - num_len);
			ft_memset((void *)pad, ' ', printinfo->width - num_len);
			if (printinfo->flags & FLAG_LEFT_JUST)
				ft_strset(&str, ft_strjoin(str, pad));
			else
				ft_strset(&str, ft_strjoin(pad, str));
			free(pad);
		}
		ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, str));
		free(str);
	}
}

void			printf_str(t_printf *printinfo, va_list list)
{
	char	*str;
	char	*pad;
	int		str_len;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	if ((str_len = ft_strlen(str)) < printinfo->width)
	{
		pad = ft_strnew(printinfo->width - str_len);
		ft_memset((void *)pad, ' ', printinfo->width - str_len);
		if (printinfo->flags & FLAG_LEFT_JUST)
			str = ft_strjoin(str, pad);
		else
			str = ft_strjoin(pad, str);
		free(pad);
	}
	ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, str));
	if (str_len < printinfo->width)
		free(str);
}

void			printf_chr(t_printf *printinfo, va_list list)
{
	char	c;
	char	*str;
	char	*pad;

	c = (char)va_arg(list, int);
	if ((str = ft_strnew(1)) != NULL)
		*str = c;
	if (printinfo->width > 1)
	{
		if ((pad = ft_strnew(printinfo->width - 1)) != NULL)
			ft_memset((void *)pad, ' ', printinfo->width - 1);
		if (printinfo->flags & FLAG_LEFT_JUST)
			ft_strset(&str, ft_strjoin(str, pad));
		else
			ft_strset(&str, ft_strjoin(pad, str));
		free(pad);
	}
	ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, str));
	if (str != NULL)
		free(str);
}
