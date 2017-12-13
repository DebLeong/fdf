/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:46:27 by dleong            #+#    #+#             */
/*   Updated: 2017/12/08 14:59:02 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 42

/*
** this needs to work when BUFF_SIZE is 9999
** this needs to work when BUFF_SIZE is 1
** this needs to work when BUFF_SIZE is 10000000
*/

int	get_next_line(const int fd, char **line);

#endif
