/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:24:07 by dleong            #+#    #+#             */
/*   Updated: 2017/12/14 01:10:15 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	bresenhams(double x1, double y1, double x2, double y2, t_fdf *fdf)
{
	t_bres	bres;

	bres.x = x1;
	bres.y = y1;
	bres.dx = fabs(x2 - x1);
	bres.dy = fabs(y2 - y1);
	bres.s1 = sign(x2 - x1);
	bres.s2 = sign(y2 - y1);
	bres.swap = 0;
	bres.i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
	if (bres.dy > bres.dx)
	{
		bres.tmp = bres.dx;
		bres.dx = bres.dy;
		bres.dy = bres.tmp;
		bres.swap = 1;
	}
	bres.p = 2 * bres.dy - bres.dx;
	while (bres.i < bres.dx)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
		while (bres.p >= 0)
		{
			bres.p = bres.p - 2 * bres.dx;
			if (bres.swap)
				bres.x = bres.x + bres.s1;
			else
				bres.y = bres.x + bres.s2;
		}
		bres.p = bres.p + 2 * bres.dy;
		if (bres.swap)
			bres.y = bres.y + bres.s2;
		else
			bres.x = bres.x + bres.s1;
		bres.i = bres.i + 1;
	}
	mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
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
		if (fdf->pt->right)
		{
			bres_cd.x2 = fdf->pt->right->cd.x;
			bres_cd.y2 = fdf->pt->right->cd.y;
			bresenhams(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
		}
		if (fdf->pt->down)
		{
			bres_cd.x2 = fdf->pt->down->cd.x;
			bres_cd.y2 = fdf->pt->down->cd.y;
			bresenhams(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
		}
		i++;
		fdf->pt = fdf->pt->next;
	}
	fdf->pt = head;
}

void	rotate(t_fdf *fdf)
{
	t_pt	*head;
	int		i;

	i = 0;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x = fdf->pt->cd.x * cos(0.7854) - fdf->pt->cd.y * sin(0.7854);
		fdf->pt->cd.y = fdf->pt->cd.x * sin(0.7854) + fdf->pt->cd.y * cos(0.7854);
		fdf->pt->cd.z = fdf->pt->cd.y * cos(0.6982) - fdf->pt->cd.z * sin(0.6982);
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
		fdf->pt->cd.x = fdf->pt->cd.x + (800 + fdf->gap * fdf->max) / 2;
		fdf->pt->cd.y = fdf->pt->cd.y + (500 + fdf->gap * fdf->max) / 2;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}

/*
void	draw_y(t_fdf *fdf)
{
	int			i;
	t_pt		*head;
	int			p;

	i = 0;
	p = 0;
	head = fdf->pt;
	while (i <= ((fdf->total_node - fdf->total_col) + 1))
	{
		if (fdf->pt->down)
		{
			fdf->dx = fabs((fdf->pt->down->cd).x - (fdf->pt->cd).x) * fdf->gap_x;
			fdf->dy = fabs((fdf->pt->down->cd).y - (fdf->pt->cd).y) * fdf->gap_y;
			p = 2 * (fdf->dy/fdf->gap_y) - (fdf->dx/fdf->gap_x);
			if ((fdf->pt->cd).x > (fdf->pt->down->cd).x)
			{
				fdf->x = ((fdf->pt->down->cd).x * fdf->gap_x) + fdf->center_x;
				fdf->y = ((fdf->pt->down->cd).y * fdf->gap_y) + fdf->center_y;
				fdf->end = ((fdf->pt->cd).x * fdf->gap_x) + fdf->center_x;
			}
			else
			{
				fdf->x = ((fdf->pt->cd).x * fdf->gap_x) + fdf->center_x;
				fdf->y = ((fdf->pt->cd).y * fdf->gap_y) + fdf->center_y;
				fdf->end = ((fdf->pt->down->cd).x * fdf->gap_x) + fdf->center_x;
			}
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
			while (fdf->x < fdf->end)
			{
				(fdf->x)++;
				if (p < 0)
					p = p + 2 * (fdf->dy/fdf->gap_y);
				else
				{
					(fdf->y)++;
					p = p + 2 * ((fdf->dy/fdf->gap_y) - (fdf->dx/fdf->gap_x));
				}
				mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
			}
		}
		i++;
		fdf->pt = fdf->pt->next;
	}
	fdf->pt = head;
}
*/
