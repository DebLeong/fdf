/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:16:05 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 12:22:46 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	set_change_values(float x, float y, float z, t_fdf *fdf)
{
	fdf->change_x = x;
	fdf->change_y = y;
	fdf->change_z = z;
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
	else
		ft_putendl("Arrow: Move\n+/-: Zoom\n1/3: Rot\nc: color\nz/x: depth");
	close(fd);
	initiate(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.win_x, fdf.win_y, "FdF 42");
	make_pixel_cd(&fdf);
	rotate(&fdf);
	translate(&fdf);
	draw_line(&fdf, 0);
	mlx_key_hook(fdf.win, key_hook1, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
