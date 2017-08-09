/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 06:55:22 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/09 07:42:16 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define FLAG_LEFT_JUST		0b00000001
# define PRINTF_BUFFSIZE	511

typedef struct	s_printf
{
	char	flags;
	int		width;
	char	modifier;
	char	*buff;
	int		printed;
}				t_printf;

typedef	void (*printfunc)(t_printf *, va_list);

int				ft_printf(const char *fmt, ...);

#endif
