/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:24:07 by dleong            #+#    #+#             */
/*   Updated: 2017/12/14 02:54:00 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	sign(int x, t_fdf *fdf)
{
	(void)fdf;
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
	bres.s1 = sign(x2 - x1, fdf);
	bres.s2 = sign(y2 - y1, fdf);
	bres.swap = 0;
	bres.i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, bres.x, bres.y, 0xFFFFFF);
	printf("x1 is %f and y1 is %f\n", bres.x, bres.y);
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
		bres.i++;
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
		//printf("current node is %i\n", fdf->pt->node);
		if (i == fdf->total_node)
			bresenhams(bres_cd.x1, bres_cd.y1, bres_cd.x1, bres_cd.y1, fdf);
		if (fdf->pt->right)
		{
			bres_cd.x2 = fdf->pt->right->cd.x;
			bres_cd.y2 = fdf->pt->right->cd.y;
			//printf("current right node is %i\n", fdf->pt->right->node);
			bresenhams(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
			//printf("x1 is %f and y1 is %f\n", bres_cd.x1, bres_cd.y1);
			//printf("x2 is %f and y2 is %f\n", bres_cd.x2, bres_cd.y2);
		}
		if (fdf->pt->down)
		{
			bres_cd.x2 = fdf->pt->down->cd.x;
			bres_cd.y2 = fdf->pt->down->cd.y;
			//printf("current down node is %i\n", fdf->pt->down->node);
			bresenhams(bres_cd.x1, bres_cd.y1, bres_cd.x2, bres_cd.y2, fdf);
			//printf("x1 is %f and y1 is %f\n", bres_cd.x1, bres_cd.y1);
			//printf("x2 is %f and y2 is %f\n", bres_cd.x2, bres_cd.y2);
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
		//z-axis rotation
		fdf->pt->cd.x = fdf->pt->cd.x * cos(0.7854) - fdf->pt->cd.y * sin(0.7854);
		fdf->pt->cd.y = fdf->pt->cd.x * sin(0.7854) + fdf->pt->cd.y * cos(0.7854);
		//x-axis rotation
		fdf->pt->cd.y = fdf->pt->cd.y * cos(0.6982) - fdf->pt->cd.z * sin(0.6982);
		fdf->pt->cd.z = fdf->pt->cd.y * sin(0.6982) + fdf->pt->cd.z * cos(0.6982);
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
		fdf->pt->cd.x = fdf->pt->cd.x + (900 + fdf->gap * fdf->max) / 2;
		fdf->pt->cd.y = fdf->pt->cd.y + (400 + fdf->gap * fdf->max) / 2;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}
