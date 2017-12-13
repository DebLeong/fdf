/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:25:48 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 22:07:52 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	int		result;
	char	*s3;
	char	*s4;

	i = 0;
	result = 0;
	s3 = (char *)s1;
	s4 = (char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s3[i] == s4[i] && (i + 1) < (int)n)
		i++;
	if (i == (int)n)
		return (0);
	else
		return ((unsigned char)s3[i] - (unsigned char)s4[i]);
}
