#include <stdio.h>

#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

static t_map	*init_func_map(void)
{
	t_map	*map;

	map = create_map();
/*	add_val(map, 'd', (void *)&printf_num);
	add_val(map, 's', (void *)&printf_str);
	add_val(map, 'c', (void *)&printf_chr);*/
	return (map);
}

static t_printf	*extract_print_info(char **fmt, t_printf *print_info)
{
	char	*fmt_c;

	fmt_c = *fmt;
	if (*fmt_c == '%')
		++fmt_c;
	while (ft_strchr("dsc", *fmt_c) == NULL)
	{
		if (ft_isdigit(*fmt_c))
		{
			print_info->width = ft_atoi(fmt_c);
			while (ft_isdigit(*fmt_c))
				++fmt_c;
		}
		else
			break ;
	}
	if (ft_strchr("dsc", *fmt_c) != NULL)
	{
		print_info->modifier = *fmt_c;
		++fmt_c;
	}
	*fmt = fmt_c;
	return (print_info);
}

int				ft_printf(char *fmt, ...)
{
	static t_map	*func_map;
	t_printf		print_info;
	va_list			ap;

	if (func_map == NULL)
		func_map = init_func_map();
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			extract_print_info(&fmt, &print_info);
			printf("w: %i; s: %c\n", print_info.width, print_info.modifier);
		}
		else
		{
			write(1, fmt, 1);
			++fmt;
		}
	}
	va_end(ap);
	return (0);
}
