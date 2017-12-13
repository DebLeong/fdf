/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:41:44 by dleong            #+#    #+#             */
/*   Updated: 2017/11/07 13:13:03 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(const int fd, char **result)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, buff);
		ft_strdel(&tmp);
	}
	return (ret);
}

static void	fill_remain(char **result, char *newline)
{
	char	*tmp;

	tmp = *result;
	*result = ft_strdup(newline + 1);
	ft_strdel(&tmp);
}

/*
** while there's no newline, get_next_line keeps reading and copying content
** into result[fd] through ft_read function call
** if it comes across a newline, it fills line from begining of result[fd]
** up to the newline pointer returned from ft_strchr
** subsequently, the fill_remain function copies content after the newline
** and store the content in the static variable result[fd]
*/

static int	free_fd(char **result, int fd)
{
	ft_strdel(&(result[fd]));
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*result[5000];
	char		*newline;
	int			read;

	if (fd < 0 || fd > 5000 || line == NULL)
		return (-1);
	if (!result[fd])
		result[fd] = ft_strnew(1);
	while (!(newline = ft_strchr(result[fd], '\n')))
	{
		if ((read = ft_read(fd, &result[fd])) < 0)
			return (-1);
		if (read == 0 && !newline)
		{
			if (result[fd][0] == '\0')
				return (free_fd(result, fd));
			*line = ft_strdup(result[fd]);
			result[fd][0] = '\0';
			return (1);
		}
	}
	*line = ft_strsub(result[fd], 0, newline - result[fd]);
	fill_remain(&result[fd], newline);
	return (1);
}
