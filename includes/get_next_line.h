/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:32:57 by pde-brui          #+#    #+#             */
/*   Updated: 2017/08/28 09:07:24 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 511
# define FT_ERR -1
# define FT_EOF 0
# define FT_NLN 1
# define FT_RDN 2

int		get_next_line(const int fd, char **line);

#endif
