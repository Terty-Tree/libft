/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-brui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:53:21 by pde-brui          #+#    #+#             */
/*   Updated: 2017/06/19 11:14:39 by pde-brui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"
#include "libft.h"

void	clear_buf(char *buf)
{
	char	tmp[BUFF_SIZE + 1];
	char	*buf_c;

	ft_bzero(tmp, sizeof(tmp));
	buf_c = buf;
	while (*buf_c != '\n' && *buf_c != '\0' && (buf_c - buf) < BUFF_SIZE)
		++buf_c;
	++buf_c;
	ft_strcpy(tmp, buf_c);
	ft_bzero(buf, sizeof(tmp));
	ft_strcpy(buf, tmp);
}

int		read_line(const int fd, char *buf, char **line)
{
	ssize_t	offs;
	char	*tmp;
	char	*nl;

	while ((offs = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[offs] = '\0';
		nl = ft_strchr(buf, '\n');
		tmp = ft_strcjoin(*line, buf, '\n');
		free(*line);
		*line = tmp;
		clear_buf(buf);
		if (nl != NULL || offs < BUFF_SIZE)
			break ;
	}
	if (offs == -1)
		return (-1);
	return ((ft_strlen(*line) != 0 || (nl != NULL && offs > 0))
			? FT_NLN : offs);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	char		*nl;

	if (fd < 0 || line == NULL)
		return (-1);
	nl = ft_strchr(buf, '\n');
	*line = ft_strcdup(buf, '\n');
	clear_buf(buf);
	if (nl != NULL)
		return (FT_NLN);
	return (read_line(fd, buf, line));
}
