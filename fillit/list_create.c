/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:00:49 by sirvin            #+#    #+#             */
/*   Updated: 2019/12/14 14:33:49 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_tetr *list)
{
	t_tetr	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list;
		free(tmp->str);
		list = tmp->next;
		free(tmp);
	}
}

t_tetr	*new_el(char letter, int *line)
{
	t_tetr	*new;

	if (!line)
		return (NULL);
	if (!(new = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
		return (NULL);
	new->name = letter;
	new->str = line;
	new->next = NULL;
	return (new);
}

t_tetr	*add_el(char letter, t_tetr *head, int *line)
{
	t_tetr	*tmp;
	t_tetr	*add;

	if (!line)
		return (NULL);
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	add = new_el(letter, line);
	tmp->next = add;
	return (head);
}

t_tetr	*ft_tetr(int fd, char *line)
{
	int		*tmp;
	char	letter;
	t_tetr	*head;
	t_tetr	*add;

	head = NULL;
	letter = 'A';
	while (1)
	{
		tmp = init_x(ck_fig(fd, line, NULL));
		tmp = init_y(tmp);
		if (!ft_sravnen(tmp))
			ft_error();
		if (head == NULL)
			head = new_el(letter++, tmp);
		else
			add = add_el(letter++, head, tmp);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	close(fd);
	return (head);
}
