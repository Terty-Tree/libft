#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
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
	str = ft_itoa(num);
	if ((num_len = ft_strlen(str)) < printinfo->width)
	{
		pad = ft_strnew(printinfo->width - num_len);
		ft_memset((void *)pad, ' ', printinfo->width - num_len);
		if (printinfo->flags & FLAG_LEFT_JUST)
			ft_strset(&str, ft_strjoin(str, pad));
		else
			ft_strset(&str, ft_strjoin(pad, str));
		ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, str));
		free(pad);
		free(str);
	}
}

void			printf_str(t_printf *printinfo, va_list list)
{
	char	*str;
	char	*res;
	char	*pad;
	int		str_len;

	str = va_arg(list, char *);
	if ((str_len = ft_strlen(str)) < printinfo->width)
	{
		res = NULL;
		pad = ft_strnew(printinfo->width - str_len);
		ft_memset((void *)pad, ' ', printinfo->width - str_len);
		if (printinfo->flags & FLAG_LEFT_JUST)
			res = ft_strjoin(str, pad);
		else
			res = ft_strjoin(pad, str);
		ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, res));
		free(pad);
		free(res);
	}
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
		ft_strset(&(printinfo->buff), ft_strjoin(printinfo->buff, str));
		free(pad);
	}
	if (str != NULL)
		free(str);
}

static t_map	*init_func_map(void)
{
	t_map	*map;

	map = create_map();
	add_val(map, 'd', (void *)&printf_num);
	add_val(map, 's', (void *)&printf_str);
	add_val(map, 'c', (void *)&printf_chr);
	return (map);
}

static t_printf	*extract_print_info(const char **fmt, t_printf *printinfo)
{
	const char	*fmt_c;

	printinfo->flags = 0;
	printinfo->width = 0;
	fmt_c = *fmt;
	if (*fmt_c == '%')
		++fmt_c;
	while (ft_strchr("dsc", *fmt_c) == NULL)
	{
		if (ft_isdigit(*fmt_c))
		{
			printinfo->width = ft_atoi(fmt_c);
			while (ft_isdigit(*fmt_c))
				++fmt_c;
		}
		if (*fmt_c == '-')
		{
			printinfo->flags |= FLAG_LEFT_JUST;
			++fmt_c;
		}
		else
			break ;
	}
	if (ft_strchr("dsc", *fmt_c) != NULL)
	{
		printinfo->modifier = *fmt_c;
		++fmt_c;
	}
	else
		printinfo->modifier = 0;
	*fmt = fmt_c;
	return (printinfo);
}

static void		print(t_map *printmap, t_printf *printinfo, va_list list)
{
	printfunc	print_function;

	print_function = (printfunc)get_val(printmap, printinfo->modifier);
	if (print_function != NULL)
	{
		print_function(printinfo, list);
	}
}

int				ft_printf(const char *fmt, ...)
{
	char			buff[PRINTF_BUFFSIZE + 1];
	int				index;
	static t_map	*func_map;
	t_printf		printinfo;
	va_list			ap;

	ft_bzero(buff, sizeof(buff));
	index = 0;
	if (func_map == NULL)
		func_map = init_func_map();
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			extract_print_info(&fmt, &printinfo);
			print(func_map, &printinfo, ap);
		}
		while (*fmt != '\0' && *fmt != '%')
		{
			buff[index++] = *fmt;
			if (index >= PRINTF_BUFFSIZE)
			{
				ft_strset(&(printinfo.buff), ft_strjoin(printinfo.buff, buff));
				index = 0;
				ft_bzero(buff, sizeof(buff));
			}
			++fmt;
		}
	}
	va_end(ap);
	ft_strset(&(printinfo.buff), ft_strjoin(printinfo.buff, buff));
	write(1, printinfo.buff, ft_strlen(printinfo.buff));
	return (0);
}
