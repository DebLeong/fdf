/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:16:05 by dleong            #+#    #+#             */
/*   Updated: 2017/12/14 02:54:02 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//REMOVEEEEEEEEEEEEEEEETHISSSSSSSSSSSSSSSSSSsssssssssssssssssssssssssssssssssss
#include "stdio.h"

int	key_hook(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

/*
int	get_hook(t_fdf *fdf)
{
	(void)fdf;
	draw_line(fdf);
	return (1);
}
*/

void	print_list(t_fdf *fdf)
{
	int i = 0;

	while (fdf->pt && fdf->pt->next)
	{
		printf("node_curr %i\n", fdf->pt->node);
		/*
		printf("x: %f\n", fdf->pt->cd.x);
		printf("y: %f\n", fdf->pt->cd.y);
		printf("z: %f\n", fdf->pt->cd.z);
		*/
		if (fdf->pt->right)
			printf("node_right: %i\n", fdf->pt->right->node);
		if (fdf->pt->down)
			printf("node_down: %i\n", fdf->pt->down->node);
		fdf->pt = fdf->pt->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf <filename>");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("Error reading file");
		return (0);
	}

	if (!(parse(fd, &fdf)))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	map_right(&fdf);
	map_down(&fdf);
	
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "FdF 42 dleong");
	fdf.win_mid_x = 1920 / 2;
	fdf.win_mid_y = 1080 / 2;
	if (fdf.total_col > fdf.total_row)
		fdf.max = fdf.total_col;
	else
		fdf.max = fdf.total_row;
	fdf.gap = 800 / fdf.max;

	make_pixel_cd(&fdf);
	rotate(&fdf);
	translate(&fdf);
	draw_line(&fdf);

	//REMOVE THISSSSSSSSSSSSSSSSSSSSSSSSSS
	//print_list(&fdf);

	close (fd);

	//mlx_expose_hook(fdf.win, get_hook, &fdf);

	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);

	free(&fdf);
	return (0);
}
