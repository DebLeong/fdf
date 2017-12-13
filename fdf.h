/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:59:46 by dleong            #+#    #+#             */
/*   Updated: 2017/12/12 22:42:39 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_point
{
	int				node;
	t_coord			coord;
	struct s_point	*next;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct		s_master
{
	void			*mlx;
	void			*win;
	char			**map_line;
	t_point			*point;
	int				total_column;
	int				total_row;
}					t_master;

int					parse(int fd, t_master *master);
int					key_hook(int keycode, void *param);
int					get_hook(t_master *master);

#endif
