/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:04:36 by dleong            #+#    #+#             */
/*   Updated: 2017/12/15 03:05:03 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
