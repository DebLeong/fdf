/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:16:05 by dleong            #+#    #+#             */
/*   Updated: 2017/12/12 22:42:37 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//REMOVEEEEEEEEEEEEEEEETHISSSSSSSSSSSSSSSSSS
#include "stdio.h"

int	key_hook(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

/*
int	get_hook(t_master *master)
{
	draw_y(master);
	draw_x(master);
	return (1);
}
*/

/*
void	print_list(t_master *master)
{
	while ((master->point) && (master->point->next))
	{
		printf("node %i\n", master->point->node);
		printf("x: %f\n", (master->point->coord).x);
		printf("y: %f\n", (master->point->coord).y);
		printf("z: %f\n", (master->point->coord).z);
		master->point = master->point->next;
	}
}
*/

int	parse(int fd, t_master *master)
{
	char	*line;
	t_point *tmp;
	int		x;
	int		y;
	int		z;
	int		i;

	x = 0;
	y = 0;
	z = 0;
	i = 1;
	master->point = ft_memalloc(sizeof(t_point));
	tmp = master->point;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(master->map_line = ft_strsplit(line, ' ')))
			return (0);
		while ((master->map_line)[x])
		{
			//malloc
			master->point->node = i;
			(master->point->coord).x = x;
			(master->point->coord).y = y;
			(master->point->coord).z = ft_atoi(master->map_line[z]);
			x++;
			z++;
			//malloc
			master->point->next = ft_memalloc(sizeof(t_point));
			//printf("this is node %i\n", master->point->node);
			master->point = master->point->next;
			i++;
		}
		master->total_column = x;
		x = 0;
		z = 0;
		y++;
		free (line);
		line = 0;
	}
	master->total_row = y;
	//printf("total column is %i\n", master->total_column);
	//printf("total row is %i\n", master->total_row);
	master->point = tmp;
	return (1);
}

int main(int argc, char **argv)
{
	t_master	master;
	int			fd;
	
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	if ((!(fd = open(argv[1], O_RDONLY)) || (!(parse(fd, &master)))))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	/*
	if (!(parse(fd, &master)))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	*/
	close (fd);

	//REMOVE THISSSSSSSSSSSSSSSSSSSSSSSSSS
	//print_list(&master);
	
	master.mlx = mlx_init();
	master.win = mlx_new_window(master.mlx, 1920, 1080, "FdF 42 dleong");

	mlx_expose_hook(master.win, get_hook, &master);	
	mlx_key_hook(master.win, key_hook, &master);
	mlx_loop(master.mlx);
	return (0);
}
