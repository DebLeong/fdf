/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:31:13 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 12:52:29 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		ft_error("Error: reading line");
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			ft_error("Error: found alphabet chars");
		if ((str[i] == '-' && !(ft_isdigit(str[i + 1]))) ||
			str[i] == '\t')
			ft_error("Error: found forbidden chars");
		i++;
	}
}

void	check_width(int fd, int i, t_fdf *fdf)
{
	if (get_next_line(fd, &fdf->line))
	{
		check_line(fdf->line);
		if (!(fdf->map_line = ft_strsplit(fdf->line, ' ')))
			ft_error("Error: content");
		while (fdf->map_line[i])
			i++;
		fdf->total_col = i;
		fdf->total_row += 1;
		free_2d(&fdf->map_line);
		ft_strdel(&fdf->line);
	}
	else
		ft_error("Empty File");
	i = 0;
	while (get_next_line(fd, &fdf->line))
	{
		check_line(fdf->line);
		if (!(fdf->map_line = ft_strsplit(fdf->line, ' ')))
			ft_error("Error: content");
		while (fdf->map_line[i])
			i++;
		if (i != fdf->total_col)
			ft_error("Error: width");
		fdf->total_row += 1;
		free_2d(&fdf->map_line);
		ft_strdel(&fdf->line);
	}
}
