/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 07:27:53 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/12 08:17:55 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CP_VEC_H
# define CP_VEC_H

typedef struct	s_cp_vec
{
	char	**vals;
	int		size;
	int		capacity;
}				t_cp_vec;

t_cp_vec		*cp_vec_new(int size);
t_cp_vec		*cp_vec_cpy(t_cp_vec *dst, t_cp_vec *src);
t_cp_vec		*cp_vec_add(t_cp_vec *vec, char *val);
void			cp_vec_free(t_cp_vec **vec);

#endif