/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshor <rshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:41:37 by rshor             #+#    #+#             */
/*   Updated: 2022/01/06 18:44:06 by rshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	int			i;
	char		*buf;
	int			ret;

	i = 0;
	ret = 1;
	buf = (char *)malloc(100000);
	if (!buf)
		return (-1);
	while (ret)
	{
		ret = read(0, &(buf[i]), 1);
		if (ret == -1)
			return (-1);
		if (buf[i] == '\n' || !(buf[i]))
		{
			buf[i] = '\0';
			break ;
		}
		i++;
	}
	*line = buf;
	if (!ret)
		return (0);
	return (1);
}
