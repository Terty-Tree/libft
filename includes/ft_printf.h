/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 06:55:22 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/08 14:04:40 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

typedef struct	s_printf
{
	int		width;
	char	modifier;
}				t_printf;

int				ft_printf(char *fmt, ...);

#endif
