/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:40:54 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 14:44:58 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*result;
	char	*source;

	i = 0;
	result = dst;
	source = (char *)src;
	while (i < n)
	{
		result[i] = source[i];
		i++;
	}
	return (result);
}
