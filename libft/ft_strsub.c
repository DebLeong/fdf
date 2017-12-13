/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:02:52 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 23:18:41 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)s + start;
	s1 = (char *)ft_strnew(sizeof(char) * len);
	if (!s1)
		return (NULL);
	while (s[start] != '\0' && i < (int)len)
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	return (s1);
}
