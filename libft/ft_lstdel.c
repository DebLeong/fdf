/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:39:05 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 11:22:18 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*findnext;

	if (alst)
	{
		while (*alst)
		{
			findnext = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = findnext;
		}
	}
}
