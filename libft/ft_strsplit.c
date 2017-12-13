/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 13:40:21 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	result = NULL;
	if (s)
	{
		i = 0;
		words = ft_gc(s, c);
		if (!(result = (char **)malloc((sizeof(char *) * words) + 1)))
			return (NULL);
		while (words--)
		{
			while (*s == c && *s != '\0')
				s++;
			if (!(result[i] = ft_strsub(s, 0, ft_gl(s, c))))
				return (NULL);
			s = s + ft_gl(s, c);
			i++;
		}
		result[i] = NULL;
	}
	return (result);
}
