/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_makepixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:01:51 by dleong            #+#    #+#             */
/*   Updated: 2018/02/02 10:01:51 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate(t_fdf *fdf)
{
	if (fdf->total_col > fdf->total_row)
		fdf->max = fdf->total_col;
	else
		fdf->max = fdf->total_row;
	if (fdf->max < fdf->total_z)
		fdf->max = fdf->total_z;
	fdf->gap = 700 / fdf->max;
	fdf->win_y = 1080;
	fdf->win_x = 1920;
	fdf->color = 0xFFFF;
}

void	make_pixel_cd(t_fdf *fdf)
{
	t_pt	*head;
	int		i;
	int		j;

	i = 0;
	j = 1;
	head = fdf->pt;
	while (i <= fdf->total_node)
	{
		fdf->pt->cd.x += (fdf->pt->cd.x - fdf->total_col / 2) * fdf->gap;
		fdf->pt->cd.y += (fdf->pt->cd.y - fdf->total_row / 2) * fdf->gap;
		fdf->pt->cd.z = fdf->pt->cd.z * 10;
		fdf->pt = fdf->pt->next;
		i++;
	}
	fdf->pt = head;
}
