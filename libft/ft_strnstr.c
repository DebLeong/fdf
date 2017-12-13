/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:12:01 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 16:02:48 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	curr;

	i = 0;
	j = 0;
	if ((int)ft_strlen(little) == 0)
		return ((char *)big);
	if (big == little)
		return ((char *)&big[0]);
	while (big[i] != '\0' && i < (int)len)
	{
		curr = i;
		j = 0;
		while (little[j] != '\0' && big[i] == little[j] && i < (int)len)
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[curr]);
		}
		i = curr + 1;
	}
	return (NULL);
}
