/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:48:08 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 23:18:13 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	result;

	if (!s1 || !s2)
		return (0);
	if ((int)n == 0)
		return (1);
	result = (int)ft_strncmp(s1, s2, n);
	if (result == 0)
		return (1);
	return (0);
}
