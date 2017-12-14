/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:59:46 by dleong            #+#    #+#             */
/*   Updated: 2017/12/14 01:10:17 by dleong           ###   ########.fr       */
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

typedef struct		s_cd
{
	double			x;
	double			y;
	double			z;
}					t_cd;

typedef struct		s_pt
{
	int				node;
	t_cd			cd;
	struct s_pt		*next;
	struct s_pt		*right;
	struct s_pt		*down;
}					t_pt;

typedef struct		s_bres
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	int				swap;
	double			tmp;
	int				s1;
	int				s2;
	double			p;
	int				i;
}					t_bres;

typedef struct		s_bres_cd
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}					t_bres_cd;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	char			**map_line;
	t_pt			*pt;
	int				total_col;
	int				total_row;
	int				total_node;
	int				win_mid_x;
	int				win_mid_y;
	int				gap;
	int				max;
}					t_fdf;

int					parse(int fd, t_fdf *fdf);
void				map_right(t_fdf *fdf);
void				map_down(t_fdf *fdf);
void				make_pixel_cd(t_fdf *fdf);

void				translate(t_fdf *fdf);
void				rotate(t_fdf *fdf);
void				draw_line(t_fdf *fdf);
int					sign(int x);
void				bresenhams(double x1, double y1, double x2, double y2, t_fdf *fdf);

int					key_hook(int keycode, void *param);
//int				get_hook(t_fdf *fdf);

#endif
