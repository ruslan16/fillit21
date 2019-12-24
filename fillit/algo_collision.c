/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:21:58 by etristan          #+#    #+#             */
/*   Updated: 2019/12/14 15:13:51 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		hi_x(int *fig)
{
	int		size;
	int		i;
	int		x;

	i = 0;
	size = 3;
	x = fig[i];
	while (size--)
	{
		i = i + 2;
		if (x < fig[i])
			x = fig[i];
	}
	return (x);
}

int		hi_y(int *fig)
{
	int		size;
	int		i;
	int		y;

	i = 1;
	size = 3;
	y = fig[i];
	while (size--)
	{
		i = i + 2;
		if (y < fig[i])
			y = fig[i];
	}
	return (y);
}

int		one_bump(char **field, int *fig)
{
	int size;
	int i;

	i = 0;
	size = 4;
	while (size--)
	{
		if (field[fig[i + 1]][fig[i]] != '.')
			return (1);
		i = i + 2;
	}
	return (0);
}

int		box_bump(int *fig, int size)
{
	int x;
	int y;

	x = hi_x(fig);
	y = hi_y(fig);
	if (x >= size || y >= size)
		return (1);
	return (0);
}

int		tetra_bump(char **field, int *fig, int size)
{
	return (!(box_bump(fig, size)) && !(one_bump(field, fig)));
}
