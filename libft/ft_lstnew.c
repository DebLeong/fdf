/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:11:05 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 10:24:12 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlst->content = ft_memalloc(content_size)))
		{
			free(newlst);
			return (NULL);
		}
		ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
	}
	else
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	newlst->next = NULL;
	return (newlst);
}
