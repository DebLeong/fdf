/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:33:23 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 12:53:43 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newhead;
	t_list	*curr;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(curr = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	newhead = curr;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(curr->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		curr = curr->next;
	}
	return (newhead);
}
