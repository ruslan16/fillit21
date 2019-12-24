/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:58:20 by etristan          #+#    #+#             */
/*   Updated: 2019/11/23 17:38:25 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		ck_valid_block(int n, char *line)
{
	int		count_sym;
	int		i;

	count_sym = ft_strlen(line);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	if (count_sym != 4 && n != 5)
		return (-1);
	if (n == 5 && count_sym > 0)
		return (-1);
	if (n == 5 && count_sym == 0)
		return (0);
	return (n);
}

int		ft_hash(char *line)
{
	int		i;
	int		count_hash;

	i = 0;
	count_hash = 0;
	while (line[i])
	{
		if (line[i] == '#')
			count_hash++;
		i++;
	}
	return (count_hash);
}

int		ft_ck_block(int fd, char *line)
{
	int num_line;
	int count_hash;
	int i;

	num_line = 1;
	count_hash = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if ((num_line = ck_valid_block(num_line, line)) < 0)
			ft_error();
		if ((count_hash = count_hash + ft_hash(line)) > 4)
			ft_error();
		if (num_line == 4)
			count_hash = 0;
		if (num_line == 0 && (i++) > 24)
			ft_error();
		free(line);
		num_line++;
	}
	if (num_line < 4)
		ft_error();
	return (1);
}
