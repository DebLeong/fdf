/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:49:03 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 22:08:05 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*result;
	unsigned char	*source;

	i = -1;
	result = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (result >= source)
		while ((int)--len >= 0)
			result[len] = source[len];
	else
		while ((int)len > ++i)
			result[i] = source[i];
	return (dst);
}
