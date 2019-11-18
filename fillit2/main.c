/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:21:58 by etristan          #+#    #+#             */
/*   Updated: 2019/11/09 20:06:50 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		*ft_write(int x, int y)
{
	int		*str;

	if (!(str = (int *)malloc(sizeof(int) * 8)))
		return (NULL);
	str[0] = x;
	str[1] = y;
	ft_putnbr(str[0]);
	ft_putnbr(str[1]);
	ft_putstr("\n");
	return (str);
}

int		ck_fig(int n, char *line)
{
	int 	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
			ft_write(i, n - 1);
		i++;
	}
	return (i);
}

/*int		ck_valid(int n, char *line)
{
	int		count_sym;
	int 	count_str;
	int 	count_dotresh;
	int		i;

	count_str = n % 5;
	count_sym = ft_strlen(line);
	count_dotresh = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#' || line[i] == '.')
			count_dotresh++;
		i++;
	}
	if (count_dotresh != count_sym)
		return (-1);
	if ((count_sym != 4 && count_str != 0))
	{
		ft_putstr("\nERR: not valid line\n");
		return (-1);
	}
	if (count_str == 0 && count_sym > 0)
	{
		ft_putstr("\nERR: not valid separator\n");
		return (-1);
	}
	else if (count_str == 0 && count_sym == 0 && (count_dotresh == count_sym))
	{
		return (n);
		ft_putstr("\nOK: valid separator\n\n");

	}
	return (0);
}*/

int		ck_valid_block(int n, char *line)
{
	int 	count_sym;
	int 	i;

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
	{
		printf("%d", n);
		ft_putstr("\nERR: not valid line\n");
		return (-1);
	}
	if (n == 5 && count_sym == 0)
		return (0);
	return (n);
}

int		ft_hash(char *line)
{
	int 	i;
	int 	count_hash;

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

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		ft_line(int fd, char *line)
{
	int		num_line;
	int 	count_hash;
	int 	i;

	num_line = 1;
	count_hash = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		printf("%d, %s\n", num_line, line);
		if ((num_line = ck_valid_block(num_line, line)) < 0) {
			//ft_putstr("\nERR: not valid field\n");
			ft_error();
		}
		if ((count_hash = count_hash + ft_hash(line)) > 4)
			ft_error();
		if (num_line == 4)
			count_hash = 0;
		if (num_line == 0 && (i++) > 24)
			ft_error();
		ck_fig(num_line, line);
		free(line);
		num_line++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		if ((fd = open(*++argv, O_RDONLY)) == -1)
			return (1);
		ft_line(fd, line);
		close(fd);
	}
	else
	{
		ft_putstr("usage: fillit \"path_to/file_dot_fillit\"\n");
	}
	return (0);
}
