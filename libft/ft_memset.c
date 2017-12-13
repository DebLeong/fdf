/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:01:13 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 10:35:09 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*result;
	size_t			i;

	result = b;
	i = 0;
	while (i < len)
	{
		result[i] = (unsigned char)c;
		i++;
	}
	return (result);
}
