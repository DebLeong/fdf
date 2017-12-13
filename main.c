/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:16:05 by dleong            #+#    #+#             */
/*   Updated: 2017/12/13 13:44:46 by dleong           ###   ########.fr       */
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

int	get_hook(t_master *master)
{
	(void)master;
	//draw_y(master);
	//draw_x(master);
	return (1);
}

void	print_list(t_master *master)
{
	int i = 0;

	while (master->point && master->point->next)
	{
		printf("node_curr %i\n", master->point->node);
		//printf("x: %f\n", (master->point->coord).x);
		//printf("y: %f\n", (master->point->coord).y);
		//printf("z: %f\n", (master->point->coord).z);
		if (master->point->right)
			printf("node_right: %i\n", master->point->right->node);
		if (master->point->down)
			printf("node_down: %i\n", master->point->down->node);
		master->point = master->point->next;
		i++;
	}
}

void	map_down(t_master *master)
{
	t_point	*head;
	t_point *current;
	t_point *tmp;
	int i;
	int a;
	int start;

	i = 0;
	a = 1;
	start = 0;
	head = master->point;
	current = master->point;
	while (i < (master->total_node - master->total_column + 1))
	{
		tmp = master->point->next;
		start = i;
		while (a != (master->total_column + 1))
		{
			master->point = master->point->next;
			a++;
		}
		current->down = master->point;
		start++;
		master->point = current;
		current = current->next;
		i++;
		a = 0;
	}
	master->point = head;
}

void	map_right(t_master *master)
{
	t_point	*head;
	int		i;

	i = 0;
	head = master->point;
	while (i < master->total_node)
	{
		if (i == 0)
			master->point->right = master->point->next;
		if (((i % (master->total_column - 1)) != 0) && (i != 0))
			master->point->right = master->point->next;
		master->point = master->point->next;
		i++;
	}
	master->point = head;
}

int	parse(int fd, t_master *master)
{
	char	*line;
	t_point *head;
	int		x;
	int		y;
	int		z;
	int		i;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	//malloccccccccccccccccccccccccccccccccccccccccccccccccc
	master->point = ft_memalloc(sizeof(t_point));
	head = master->point;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(master->map_line = ft_strsplit(line, ' ')))
			return (0);
		while ((master->map_line)[x])
		{
			master->point->node = i;
			(master->point->coord).x = x;
			(master->point->coord).y = y;
			(master->point->coord).z = ft_atoi(master->map_line[z]);
			x++;
			z++;
			//mallocccccccccccccccccccccccccccccccccccccccccccccccc
			master->point->next = ft_memalloc(sizeof(t_point));
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
	master->total_node = i - 1;
	master->point = head;
	return (1);
}

int main(int argc, char **argv)
{
	t_master	master;
	int			fd;
	
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

	if (!(parse(fd, &master)))
	{
		write (1, "Error\n", 6);
		return (0);
	}

	map_right(&master);
	map_down(&master);

	//REMOVE THISSSSSSSSSSSSSSSSSSSSSSSSSS
	print_list(&master);
	
	close (fd);

	master.mlx = mlx_init();
	master.win = mlx_new_window(master.mlx, 1920, 1080, "FdF 42 dleong");

	mlx_expose_hook(master.win, get_hook, &master);	
	mlx_key_hook(master.win, key_hook, &master);
	mlx_loop(master.mlx);

	free(&master);
	return (0);
}
