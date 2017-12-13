/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:12:01 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 23:59:06 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		little_len;
	int		big_len;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (little_len == 0)
		return ((char *)big);
	while (i < big_len)
	{
		if (ft_strncmp(&big[i], &little[j], (size_t)little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
