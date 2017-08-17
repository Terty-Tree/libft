/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:55:59 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/17 11:28:46 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf.h"
#include "libft"

char	*parse_conv_spec(const char *fmt, t_printf *printinfo)
{
	printinfo->flags = 0;
	printinfo->width = 0;
	printinfo->specifier = 0;
	while (ft_strchr(SPECIFIERS, *fmt) != NULL)
	{
		if (ft_isdigit(*fmt))
		{
			printinfo->width = ft_atoi(fmt);
			while (ft_isdigit(*fmt))
				++fmt;
		}
		else if (ft_strchr(FLAGS, *fmt) != NULL)
		{
			printinfo->flags |= *fmt == '-' ? FLAG_LEFT_JUST : 0;
		}
		else
			break ;
	}
	if (ft_strchr(SPECIFIERS, *fmt) != NULL)
		printinfo->specifier = *fmt;
	return (printinfo->specifier == 0 ? fmt : fmt + 1);
}

char	*write_to_str(char **str, char *buff, int *index)
{
	char	*tmp;

	buff[*index] = '\0';
	if ((tmp = *str) != NULL)
	{
		*str = ft_strnew(ft_strlen(tmp) + ft_strlen(buff));
		ft_memcpy(*str, tmp, ft_strlen(tmp));
		ft_strcat(*str, buff);
	}
	else
	{
		*str = ft_strdup(buff);
	}
	*index = 0;
	return (*str);
}

char	*parse_fmt(char **ret, const char *fmt, va_list ap)
{
	t_printf	printinfo;
	char		buff[PRINT_BUFF + 1];
	int			index;

	index = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			write_to_str(ret, buff, &index);
			fmt = parse_conv_spec(fmt, &printinfo);
		}
		else
		{
			buff[index] = *fmt;
			if (++index >= PRINT_BUFF)
				write_to_str(ret, buff, &index);
			++fmt;
		}
	}
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	parse_fmt(ret, fmt, ap);
	va_end(ap);
}
