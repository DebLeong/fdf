/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:59:46 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 12:42:11 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_cd
{
	float			x;
	float			y;
	float			z;
}					t_cd;

typedef struct		s_count
{
	int				x;
	int				y;
	int				z;
	int				i;
}					t_count;

typedef struct		s_pt
{
	int				node;
	t_cd			cd;
	int				color;
	struct s_pt		*next;
	struct s_pt		*right;
	struct s_pt		*down;
}					t_pt;

typedef struct		s_bres
{
	float			x;
	float			y;
	float			dx;
	float			dy;
	int				swap;
	float			tmp;
	int				end;
	float			s1;
	float			s2;
	float			p;
	float			i;
}					t_bres;

typedef struct		s_bres_cd
{
	float			*xy1;
	float			*xy2;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
}					t_bres_cd;

typedef struct		s_fdf
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	void			*mlx;
	void			*win;
	char			**map_line;
	char			*line;
	t_pt			*pt;
	int				total_col;
	int				total_row;
	int				total_z;
	int				total_node;
	int				win_x;
	int				win_y;
	int				gap;
	float			max;
	float			change_x;
	float			change_y;
	float			change_z;
	int				color;
}					t_fdf;

void				free_2d(char ***arr_2d);
void				ft_error(char *str);
void				check_line(char *str);
void				check_width(int fd, int i, t_fdf *fdf);
int					read_file(int fd, t_fdf *fdf, char *argv1);
void				initiate(t_fdf *fdf);
void				set_count(t_count *count);
int					parse(int fd, t_fdf *fdf, t_count count);
void				map_right(t_fdf *fdf);
void				map_down(t_fdf *fdf, int a, int start, int i);
void				make_pixel_cd(t_fdf *fdf);
void				translate(t_fdf *fdf);
void				rotate(t_fdf *fdf);
void				rotate_z(t_fdf *fdf, int dir);
void				draw_line(t_fdf *fdf, int i);
float				sign(int x);
void				set_bres(t_bres *bres, t_fdf *fdf, int swap);
void				b_algo(t_fdf *fdf);
int					key_hook1(int keycode, t_fdf *fdf);
int					key_hook2(int keycode, t_fdf *fdf);
int					key_hook3(int keycode, t_fdf *fdf);
void				re_translate(t_fdf *fdf);
void				scaling(t_fdf *fdf);
void				z_scaling(t_fdf *fdf);
void				random_color(t_fdf *fdf);
void				set_change_values(float x, float y, float z, t_fdf *fdf);

#endif
