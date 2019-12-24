/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:15:22 by sirvin            #+#    #+#             */
/*   Updated: 2019/12/14 14:52:48 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetr_put(char **field, int *fig, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		y = fig[i + 1];
		x = fig[i];
		field[y][x] = letter;
		i = i + 2;
	}
}

void	tetr_rem(char **field, int *fig)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		y = fig[i + 1];
		x = fig[i];
		field[y][x] = '.';
		i = i + 2;
	}
}

int		tetra_solver(char **field, t_tetr *list, int size)
{
	int *fig;
	int x;
	int y;

	y = -1;
	if (!(fig = (int *)malloc(sizeof(int) * 8)))
		return (0);
	if (!list)
	{
		free(fig);
		return (1);
	}
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			ft_intdup(fig, list->str);
			tetra_shift(fig, x, y);
			if (tetra_helper(field, fig, list, size))
				return (1);
		}
	}
	free(fig);
	return (0);
}

int		tetra_helper(char **field, int *fig, t_tetr *list, int size)
{
	if (tetra_bump(field, fig, size))
	{
		tetr_put(field, fig, list->name);
		if (tetra_solver(field, list->next, size))
		{
			free(fig);
			return (1);
		}
		tetr_rem(field, fig);
	}
	return (0);
}

void	tetra_printer(char **field, int size)
{
	int		i;

	i = -1;
	while (field[++i])
	{
		ft_putstr(field[i]);
		ft_putchar('\n');
	}
	free_field(field, size);
}
