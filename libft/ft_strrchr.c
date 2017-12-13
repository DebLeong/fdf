/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:29:10 by dleong            #+#    #+#             */
/*   Updated: 2017/09/21 00:39:31 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*src;
	int		src_len;

	src = (char *)s;
	src_len = ft_strlen(src);
	i = src_len - 1;
	j = 0;
	while (src && i >= j)
	{
		if (src[i] == (char)c)
			return (&src[i]);
		i--;
	}
	if ((src[src_len]) == '\0' && c == '\0')
		return (&src[src_len]);
	return (NULL);
}
