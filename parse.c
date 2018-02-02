/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:50:32 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 12:32:32 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		if ((((i + 1) % (fdf->total_col)) != 0) && (i != 0))
			fdf->pt->right = fdf->pt->next;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

void	map_down(t_fdf *fdf, int a, int start, int i)
{
	t_pt	*head;
	t_pt	*current;
	t_pt	*tmp;

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

void	set_count(t_count *count)
{
	count->y = 0;
	count->i = -1;
	count->x = -1;
	count->z = -1;
}

void	free_2d(char ***arr_2d)
{
	int i;

	i = -1;
	while ((*arr_2d)[++i])
		ft_strdel(&(*arr_2d)[i]);
	free(*arr_2d);
	*arr_2d = 0;
}

int		parse(int fd, t_fdf *fdf, t_count count)
{
	t_pt	*head;

	fdf->pt = ft_memalloc(sizeof(t_pt));
	head = fdf->pt;
	while (get_next_line(fd, &fdf->line) == 1)
	{
		fdf->map_line = ft_strsplit(fdf->line, ' ');
		while ((fdf->map_line)[++count.x])
		{
			fdf->pt->node = ++count.i;
			fdf->pt->cd.x = count.x;
			fdf->pt->cd.y = count.y;
			fdf->pt->cd.z = ft_atoi(fdf->map_line[++count.z]);
			if (fdf->pt->cd.z > fdf->total_z)
				fdf->total_z = fdf->pt->cd.z;
			fdf->pt->next = ft_memalloc(sizeof(t_pt));
			fdf->pt = fdf->pt->next;
		}
		count.x = -1;
		count.z = -1;
		count.y++;
		free_2d(&fdf->map_line);
		ft_strdel(&fdf->line);
	}
	fdf->pt->next = NULL;
	fdf->total_node = count.i;
	fdf->pt = head;
	return (1);
}
