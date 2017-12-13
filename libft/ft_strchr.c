/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:29:10 by dleong            #+#    #+#             */
/*   Updated: 2017/09/21 00:38:16 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;
	int		src_len;

	src = (char *)s;
	src_len = ft_strlen(src);
	i = 0;
	while (src && i < src_len)
	{
		if (src[i] == (char)c)
			return (&src[i]);
		i++;
	}
	if ((src[src_len]) == '\0' && c == '\0')
		return (&src[src_len]);
	return (NULL);
}
