/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:14:30 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 22:05:52 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*result;
	unsigned char	*source;
	size_t			i;

	i = 0;
	source = (unsigned char *)src;
	result = (unsigned char *)dst;
	while (i < n)
	{
		result[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (result + i + 1);
		i++;
	}
	return (NULL);
}
