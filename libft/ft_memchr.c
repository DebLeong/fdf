/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:08:06 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 16:25:39 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*result;
	char	*src;

	i = 0;
	src = (char *)s;
	while (i < (int)n)
	{
		if (src[i] == (char)c)
		{
			result = &src[i];
			return (result);
		}
		i++;
	}
	return (NULL);
}
