/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:15:22 by sirvin            #+#    #+#             */
/*   Updated: 2019/12/14 15:35:42 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_intdup(int *dst, int *src)
{
	int	*tmp;
	int i;

	i = 0;
	tmp = dst;
	while (i < 8)
	{
		tmp[i] = src[i];
		i++;
	}
	return (1);
}

int		*x_shift(int *list, int x)
{
	int	i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		list[i] = list[i] + x;
		i = i + 2;
	}
	return (list);
}

int		*y_shift(int *list, int y)
{
	int	i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		list[i] = list[i] + y;
		i = i + 2;
	}
	return (list);
}

int		*tetra_shift(int *list, int x, int y)
{
	list = x_shift(list, x);
	list = y_shift(list, y);
	return (list);
}
