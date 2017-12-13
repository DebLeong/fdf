/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:44:20 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 23:17:47 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 && s2)
	{
		i = 0;
		if ((int)ft_strlen(s1) != (int)ft_strlen(s2))
			return (0);
		while (s1[i] != '\0' && s1[i] == s2[i])
			i++;
		if (i == (int)ft_strlen(s1))
			return (1);
	}
	return (0);
}
