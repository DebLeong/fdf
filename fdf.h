/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:59:46 by dleong            #+#    #+#             */
/*   Updated: 2017/12/15 02:07:36 by dleong           ###   ########.fr       */
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
	void			*mlx;
	void			*win;
	char			**map_line;
	t_pt			*pt;
	int				total_col;
	int				total_row;
	int				total_z;
	int				total_node;
	int				win_x;
	int				win_y;
	int				gap;
	float			max;
}					t_fdf;

int					read_file(int fd, t_fdf *fdf);
void				initiate(t_fdf *fdf);
int					parse(int fd, t_fdf *fdf);
void				map_right(t_fdf *fdf);
void				map_down(t_fdf *fdf, int a, int start, int i);
void				make_pixel_cd(t_fdf *fdf);
void				translate(t_fdf *fdf);
void				rotate(t_fdf *fdf);
void				draw_line(t_fdf *fdf);
float				sign(int x);
void				b_algo(float x1, float y1, float x2, float y2, t_fdf *fdf);
int					key_hook(int keycode, void *param);

#endif
