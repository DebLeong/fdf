/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:02:06 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 23:17:08 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = ((char *)ft_strnew(sizeof(char) * (int)ft_strlen(s)));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
