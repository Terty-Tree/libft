/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 08:37:55 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 13:21:23 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

static void			extract_print_info(const char **fmt, t_printf *printinfo)
{
	const char	*fmt_c;

	init_printf(printinfo, 0);
	fmt_c = *fmt;
	++fmt_c;
	while (ft_strchr("dsc", *fmt_c) == NULL)
	{
		if (ft_isdigit(*fmt_c))
			fmt_c = printf_handle_num(fmt_c, printinfo);
		else if (ft_strchr(FLAGS, *fmt_c) != NULL)
			fmt_c = printf_handle_flags(fmt_c, printinfo);
		else
			break ;
	}
	if (ft_strchr("dsc", *fmt_c) != NULL)
	{
		printinfo->modifier = (*fmt_c == 'i') ? 'd' : *fmt_c;
		++fmt_c;
	}
	else
		printinfo->modifier = 0;
	*fmt = fmt_c;
}

static void			print(t_printf *printinfo, va_list list)
{
	static t_map	*func_map;
	t_printfunc		print_function;
	char			*mod;

	if (func_map == NULL)
		func_map = init_func_map();
	mod = ft_strnew(1);
	*mod = printinfo->modifier;
	print_function = (t_printfunc)map_get_val(func_map, mod);
	free(mod);
	if (print_function != NULL)
		print_function(printinfo, list);
}

static void			clean_buffer(t_printf *printinfo, char *buff, int *index)
{
	ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, buff));
	*index = 0;
	ft_bzero(buff, PRINTF_BUFFSIZE);
}

static const char	*parse_fmt(const char *fmt, t_printf *printinfo,
		char *buff, va_list ap)
{
	int		index;

	index = 0;
	if (*fmt == '%')
	{
		clean_buffer(printinfo, buff, &index);
		extract_print_info(&fmt, printinfo);
		print(printinfo, ap);
	}
	while (*fmt != '\0' && *fmt != '%')
	{
		buff[index++] = *fmt;
		if (index >= PRINTF_BUFFSIZE)
			clean_buffer(printinfo, buff, &index);
		++fmt;
	}
	return (fmt);
}

int					ft_printf(const char *fmt, ...)
{
	char			buff[PRINTF_BUFFSIZE + 1];
	int				index;
	t_printf		printinfo;
	va_list			ap;

	init_printf(&printinfo, 1);
	ft_bzero(buff, sizeof(buff));
	index = 0;
	va_start(ap, fmt);
	while (*fmt)
		fmt = parse_fmt(fmt, &printinfo, buff, ap);
	va_end(ap);
	ft_strset(&(printinfo.buff), ft_strjoin(printinfo.buff, buff));
	write(1, printinfo.buff, (index = ft_strlen(printinfo.buff)));
	if (printinfo.buff != NULL)
		free(printinfo.buff);
	return (index);
}
