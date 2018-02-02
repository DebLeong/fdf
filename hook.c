/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:02:37 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 13:50:14 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook1(int keycode, t_fdf *fdf)
{
	t_pt	*tmp;

	if (keycode == 53)
	{
		while (fdf->pt != NULL)
		{
			tmp = fdf->pt->next;
			free(fdf->pt);
			fdf->pt = tmp;
		}
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	else
		mlx_clear_window(fdf->mlx, fdf->win);
	if (keycode == 8)
		fdf->color = rand();
	else if (keycode == 126)
	{
		set_change_values(0, -10, 0, fdf);
		re_translate(fdf);
	}
	else if (keycode == 125)
	{
		set_change_values(0, 10, 0, fdf);
		re_translate(fdf);
	}
	else if (keycode == 124)
	{
		set_change_values(10, 0, 0, fdf);
		re_translate(fdf);
	}
	key_hook2(keycode, fdf);
	draw_line(fdf, 0);
	return (0);
}

int		key_hook2(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
	{
		set_change_values(-10, 0, 0, fdf);
		re_translate(fdf);
	}
	else if (keycode == 69)
	{
		set_change_values(1.1, 1.1, 0, fdf);
		scaling(fdf);
	}
	else if (keycode == 78)
	{
		set_change_values(0.9, 0.9, 0, fdf);
		scaling(fdf);
	}
	else if (keycode == 7)
	{
		fdf->change_z = 1;
		z_scaling(fdf);
	}
	key_hook3(keycode, fdf);
	draw_line(fdf, 0);
	return (0);
}

int		key_hook3(int keycode, t_fdf *fdf)
{
	if (keycode == 6)
	{
		fdf->change_z = -1;
		z_scaling(fdf);
	}
	else if (keycode == 85)
		rotate_z(fdf, 1);
	else if (keycode == 83)
		rotate_z(fdf, -1);
	draw_line(fdf, 0);
	return (0);
}

void	rotate_z(t_fdf *fdf, int dir)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x = fdf->pt->cd.x - (fdf->win_x / 2);
		fdf->pt->cd.y = fdf->pt->cd.y - (fdf->win_y / 2);
		fdf->pt->cd.x = fdf->pt->cd.x * cos(0.125) - (dir * fdf->pt->cd.y * sin(0.125));
		fdf->pt->cd.y = (dir * fdf->pt->cd.x * sin(0.125)) + fdf->pt->cd.y * cos(0.125);
		fdf->pt->cd.x *= 1.01;
		fdf->pt->cd.y *= 1.01;
		fdf->pt->cd.x = fdf->pt->cd.x + (fdf->win_x / 2);
		fdf->pt->cd.y = fdf->pt->cd.y + (fdf->win_y / 2);
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

int		read_file(int fd, t_fdf *fdf, char *argv1)
{
	t_count	count;

	count.y = 0;
	count.i = -1;
	count.x = -1;
	count.z = -1;
	check_width(fd, 0, fdf);
	close(fd);
	fd = open(argv1, O_RDONLY);
	if (!(parse(fd, fdf, count)))
		ft_error("Error");
	map_right(fdf);
	map_down(fdf, 1, 0, 0);
	return (1);
}
