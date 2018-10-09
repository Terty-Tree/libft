/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 08:51:01 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 13:12:29 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "map.h"

# define FLAGS "-"
# define FLAG_LEFT_JUST		0b00000001
# define PRINTF_BUFFSIZE	511

typedef struct	s_printf
{
	char	flags;
	int		width;
	char	modifier;
	char	*buff;
}				t_printf;

typedef void	(*t_printfunc)(t_printf *, va_list);

int				ft_printf(const char *fmt, ...);

/*
**	Print functions
*/
void			printf_num(t_printf *printinfo, va_list list);
void			printf_str(t_printf *printinfo, va_list list);
void			printf_chr(t_printf *printinfo, va_list list);

/*
**	Handler functions
*/
const char		*printf_handle_num(const char *fmt, t_printf *printinfo);
const char		*printf_handle_flags(const char *fmt, t_printf *printinfo);

/*
**	Initialization functions
*/
void			init_printf(t_printf *printinfo, char clearbuff);
t_map			*init_func_map(void);

#endif
