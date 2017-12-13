/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:14:41 by dleong            #+#    #+#             */
/*   Updated: 2017/09/21 00:39:03 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	int		j;

	i = ft_strlen(s1);
	if (s1 != NULL)
	{
		s2 = malloc(sizeof(char) * i + 1);
		if (s2 != NULL)
		{
			j = 0;
			while (s1[j] != '\0')
			{
				s2[j] = s1[j];
				j++;
			}
			s2[i] = '\0';
		}
	}
	else
		return (NULL);
	return (s2);
}
