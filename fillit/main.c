/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:21:58 by etristan          #+#    #+#             */
/*   Updated: 2019/12/14 15:53:54 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_intcmp(int *s1, int *s2)
{
	int	i;

	i = 0;
	while (i <= 7 && s1[i] == s2[i])
	{
		i++;
	}
	if (i == 8)
		return (1);
	else
		return (0);
}

int		ft_sravnen(int *line)
{
	if ((ft_intcmp(line, I_TETR) == 1) || (ft_intcmp(line, IH_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, O_TETR) == 1) || (ft_intcmp(line, L_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, LR_TETR) == 1) || (ft_intcmp(line, LD_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, LL_TETR) == 1) || (ft_intcmp(line, J_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, JR_TETR) == 1) || (ft_intcmp(line, JD_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, JL_TETR) == 1) || (ft_intcmp(line, T_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, TR_TETR) == 1) || (ft_intcmp(line, TD_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, TL_TETR) == 1) || (ft_intcmp(line, S_TETR) == 1))
		return (1);
	if ((ft_intcmp(line, SR_TETR) == 1) || (ft_intcmp(line, Z_TETR) == 1) ||
		(ft_intcmp(line, ZR_TETR) == 1))
		return (1);
	return (0);
}

int		ft_lists(int fd, char *line)
{
	t_tetr	*tmp;
	int		size;
	char	**field;

	tmp = ft_tetr(fd, line);
	size = ft_size_field(tmp);
	field = init_field(size);
	while (!tetra_solver(field, tmp, size))
	{
		free_field(field, size);
		size = size + 1;
		field = init_field(size);
	}
	tetra_printer(field, size);
	ft_freelst(tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		if ((fd = open(*++argv, O_RDONLY)) == -1)
			ft_error();
		if (ft_ck_block(fd, line))
		{
			fd = open(*argv, O_RDONLY);
			ft_lists(fd, line);
		}
		else
			ft_error();
		free(line);
		close(fd);
	}
	else
	{
		ft_putstr("usage: ./fillit \"path_to/file_dot_fillit\"\n");
		return (1);
	}
	return (0);
}
