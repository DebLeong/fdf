/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:16:05 by dleong            #+#    #+#             */
/*   Updated: 2017/12/15 06:44:32 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		key_hook(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	initiate(t_fdf *fdf)
{
	if (fdf->total_col > fdf->total_row)
		fdf->max = fdf->total_col;
	else
		fdf->max = fdf->total_row;
	if (fdf->max < fdf->total_z)
		fdf->max = fdf->total_z;
	fdf->gap = 700 / fdf->max;
	fdf->win_y = 1080;
	fdf->win_x = 1920;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "FdF 42");
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

int		main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		ft_error("Usage: ./fdf <filename>");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Error: opening file");
	if (ft_strstr(argv[1], ".fdf") == 0)
		ft_error("Error: filename does not contain fdf");
	if (!(read_file(fd, &fdf, argv[1])))
		return (0);
	initiate(&fdf);
	make_pixel_cd(&fdf);
	rotate(&fdf);
	translate(&fdf);
	draw_line(&fdf, 0);
	close(fd);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	free(&fdf);
	return (0);
}
