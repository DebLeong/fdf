/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:46:52 by dleong            #+#    #+#             */
/*   Updated: 2017/09/21 00:38:30 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;
	int	j;

	i = ft_strlen(src);
	j = 0;
	if (src != NULL || dst != NULL)
	{
		while (src[j] != '\0')
		{
			dst[j] = src[j];
			j++;
		}
		dst[i] = '\0';
	}
	else
		return (NULL);
	return (dst);
}
