/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:15:22 by sirvin            #+#    #+#             */
/*   Updated: 2019/12/14 14:52:48 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_field(char **field, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&field[i]);
		i++;
	}
	free(field);
}

int		ft_count(t_tetr *list)
{
	int		i;
	t_tetr	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_size_field(t_tetr *list)
{
	int	hash;
	int	size;

	size = 2;
	hash = (ft_count(list) * 4);
	while (hash > (size * size))
		size = size + 1;
	return (size);
}

char	*init_line(int size)
{
	char	*line;
	int		i;

	i = 0;
	if (!(line = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**init_field(int size)
{
	char	**field;
	int		i;
	char	*line;

	i = 0;
	if (!(field = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(field[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		line = init_line(size);
		ft_strcpy(field[i], line);
		free(line);
		i++;
	}
	field[i] = NULL;
	return (field);
}
