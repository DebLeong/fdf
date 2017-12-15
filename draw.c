/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:24:07 by dleong            #+#    #+#             */
/*   Updated: 2017/12/15 04:58:53 by dleong           ###   ########.fr       */
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

void	set_bres(t_bres *bres, t_fdf *fdf, int swap)
{
	if (swap == 1)
	{
		bres->swap = 1;
		bres->tmp = bres->dx;
		bres->dx = bres->dy;
		bres->dy = bres->tmp;
	}
	else
	{
		bres->x = round(fdf->x1);
		bres->y = round(fdf->y1);
		bres->dx = round(fabs(fdf->x2 - fdf->x1));
		bres->dy = round(fabs(fdf->y2 - fdf->y1));
		bres->s1 = sign(fdf->x2 - fdf->x1);
		bres->s2 = sign(fdf->y2 - fdf->y1);
		bres->swap = 0;
		bres->i = 1;
		bres->p = 2.0 * bres->dy - bres->dx;
	}
}

void	b_algo(t_fdf *fdf)
{
	t_bres	bres;

	set_bres(&bres, fdf, 0);
	mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
	if (bres.dy > bres.dx)
		set_bres(&bres, fdf, 1);
	while (bres.i++ <= bres.dx)
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
			bres.x = bres.x + bres.s1;
		bres.p = bres.p + 2.0 * bres.dy;
	}
}

void	draw_line(t_fdf *fdf, int i)
{
	t_pt			*head;

	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->x1 = fdf->pt->cd.x;
		fdf->y1 = fdf->pt->cd.y;
		if (i == fdf->total_node)
			b_algo(fdf);
		if (fdf->pt->right)
		{
			fdf->x2 = fdf->pt->right->cd.x;
			fdf->y2 = fdf->pt->right->cd.y;
			b_algo(fdf);
		}
		if (fdf->pt->down)
		{
			fdf->x2 = fdf->pt->down->cd.x;
			fdf->y2 = fdf->pt->down->cd.y;
			b_algo(fdf);
		}
		i++;
		fdf->pt = fdf->pt->next;
	}
	fdf->pt = head;
}
