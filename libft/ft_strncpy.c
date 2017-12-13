/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:57:27 by dleong            #+#    #+#             */
/*   Updated: 2017/09/18 23:01:11 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	j;

	j = 0;
	if (dst != NULL || src != NULL)
	{
		if (ft_strlen(src) < len)
		{
			while (src[j] != '\0')
			{
				dst[j] = src[j];
				j++;
			}
			while (j < len)
				dst[j++] = '\0';
		}
		while (j++ < len)
			dst[j - 1] = src[j - 1];
	}
	else
		return (NULL);
	return (dst);
}
