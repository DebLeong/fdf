/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:32:27 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 23:19:49 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	int		count;
	char	*result;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	count = 0;
	while (ft_istrimspace((int)s[i]))
		i++;
	if (i == ft_strlen(s))
		return (ft_strnew(sizeof(0)));
	while (ft_istrimspace((int)s[j]))
		j--;
	if (!(result = (char *)ft_strnew(sizeof(char) * (j - i + 1))))
		return (NULL);
	while (i <= j)
	{
		result[count] = s[i];
		i++;
		count++;
	}
	return (result);
}
