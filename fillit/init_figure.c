/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:11:50 by sirvin            #+#    #+#             */
/*   Updated: 2019/12/14 15:33:13 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*init_x(int *line)
{
	int i;
	int xmin;

	i = 0;
	xmin = line[0];
	while (i <= 6)
	{
		if (xmin > line[i])
			xmin = line[i];
		i = i + 2;
	}
	i = 0;
	while (i <= 7)
	{
		if (i % 2 == 0)
			line[i] = line[i] - xmin;
		i++;
	}
	return (line);
}

int		*init_y(int *line)
{
	int i;
	int ymin;

	i = 1;
	ymin = line[1];
	while (i <= 7)
	{
		if (ymin > line[i])
			ymin = line[i];
		i = i + 2;
	}
	i = 0;
	while (i <= 7)
	{
		if (i % 2 == 1)
			line[i] = line[i] - ymin;
		i++;
	}
	return (line);
}

int		*ft_create(int n)
{
	int		*str;

	if (!(str = (int *)ft_memalloc(sizeof(int) * n)))
		return (NULL);
	return (str);
}

int		*ft_write(int start, int x, int y, int *str)
{
	int		i;

	i = start;
	str[i++] = x;
	str[i] = y;
	return (str);
}

int		*ck_fig(int fd, char *line, int *str)
{
	int		x;
	int		y;
	int		start;

	y = -1;
	if (str == NULL)
		str = ft_create(8);
	start = 0;
	while (++y <= 3)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				str = ft_write(start, x, y - 1, str);
				start = start + 2;
			}
			x++;
		}
		free(line);
	}
	return (str);
}
