/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:50:32 by dleong            #+#    #+#             */
/*   Updated: 2017/12/14 01:05:18 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_pixel_cd(t_fdf *fdf)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x = (fdf->pt->cd.x - fdf->total_col / 2) * fdf->gap;
		fdf->pt->cd.y = (fdf->pt->cd.y - fdf->total_row / 2) * fdf->gap;
		fdf->pt->cd.z = fdf->pt->cd.z * 5;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

void	map_down(t_fdf *fdf)
{
	t_pt	*head;
	t_pt *current;
	t_pt *tmp;
	int i;
	int a;
	int start;

	i = 0;
	a = 1;
	start = 0;
	head = fdf->pt;
	current = fdf->pt;
	while (i < (fdf->total_node - fdf->total_col + 1))
	{
		tmp = fdf->pt->next;
		start = i;
		while (a != (fdf->total_col + 1))
		{
			fdf->pt = fdf->pt->next;
			a++;
		}
		current->down = fdf->pt;
		start++;
		fdf->pt = current;
		current = current->next;
		i++;
		a = 0;
	}
	fdf->pt = head;
}

void	map_right(t_fdf *fdf)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i < fdf->total_node)
	{
		if (i == 0)
			fdf->pt->right = fdf->pt->next;
		if (((i % (fdf->total_col - 1)) != 0) && (i != 0))
			fdf->pt->right = fdf->pt->next;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

int	parse(int fd, t_fdf *fdf)
{
	char	*line;
	t_pt *head;
	int		x;
	int		y;
	int		z;
	int		i;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	// MALLOCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
	fdf->pt = ft_memalloc(sizeof(t_pt));
	head = fdf->pt;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(fdf->map_line = ft_strsplit(line, ' ')))
			return (0);
		while ((fdf->map_line)[x])
		{
			fdf->pt->node = i;
			(fdf->pt->cd).x = x;
			(fdf->pt->cd).y = y;
			(fdf->pt->cd).z = ft_atoi(fdf->map_line[z]);
			x++;
			z++;
			// MALLOCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
			fdf->pt->next = ft_memalloc(sizeof(t_pt));
			fdf->pt = fdf->pt->next;
			i++;
		}
		fdf->total_col = x;
		x = 0;
		z = 0;
		y++;
		free (line);
		line = 0;
	}
	fdf->total_row = y;
	fdf->total_node = i - 1;
	fdf->pt = head;
	return (1);
}
