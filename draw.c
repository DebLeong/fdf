/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:24:07 by dleong            #+#    #+#             */
/*   Updated: 2017/12/15 02:07:54 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	b_algo(float x1, float y1, float x2, float y2, t_fdf *fdf)
{
	t_bres	bres;

	bres.x = round(x1);
	bres.y = round(y1);
	bres.dx = round(fabs(x2 - x1));
	bres.dy = round(fabs(y2 - y1));
	bres.s1 = sign(x2 - x1);
	bres.s2 = sign(y2 - y1);
	bres.swap = 0;
	bres.i = 1;
	mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
	if (bres.dy > bres.dx)
	{
		bres.tmp = bres.dx;
		bres.dx = bres.dy;
		bres.dy = bres.tmp;
		bres.swap = 1;
	}
	bres.p = 2.0 * bres.dy - bres.dx;
	while (bres.i <= bres.dx)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
		while (bres.p >= 0.0)
		{
			if (bres.swap)
				bres.x = bres.x + bres.s1;
			else
				bres.y = bres.y + bres.s2;
			bres.p = bres.p - 2.0 * bres.dx;
		}
		if (bres.swap)
			bres.y = bres.y + bres.s2;
		else
		{
			bres.x = bres.x + bres.s1;
		}
		bres.p = bres.p + 2.0 * bres.dy;
		bres.i++;
	}
}

void	draw_line(t_fdf *fdf)
{
	int				i;
	t_pt			*head;
	t_bres_cd		bres_cd;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		bres_cd.x1 = fdf->pt->cd.x;
		bres_cd.y1 = fdf->pt->cd.y;
		if (i == fdf->total_node)
			b_algo(bres_cd.x1, bres_cd.y1, bres_cd.x1, bres_cd.y1, fdf);
		if (fdf->pt->right)
		{
			bres_cd.x2 = fdf->pt->right->cd.x;
			bres_cd.y2 = fdf->pt->right->cd.y;
			b_algo(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
		}
		if (fdf->pt->down)
		{
			bres_cd.x2 = fdf->pt->down->cd.x;
			bres_cd.y2 = fdf->pt->down->cd.y;
			b_algo(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
		}
		i++;
		fdf->pt = fdf->pt->next;
	}
	fdf->pt = head;
}

/*
** first 2 lines are z-axis rotation
** next 2 lines are x-axis rotation
*/

void	rotate(t_fdf *fdf)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x = fdf->pt->cd.x * cos(0.785) - fdf->pt->cd.y * sin(0.785);
		fdf->pt->cd.y = fdf->pt->cd.x * sin(0.785) + fdf->pt->cd.y * cos(0.785);
		fdf->pt->cd.y = fdf->pt->cd.y * cos(0.698) - fdf->pt->cd.z * sin(0.698);
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

void	translate(t_fdf *fdf)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x = fdf->pt->cd.x + (fdf->win_x / 2);
		fdf->pt->cd.y = fdf->pt->cd.y + (fdf->win_y / 2);
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}
