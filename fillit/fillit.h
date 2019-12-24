/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:44:13 by etristan          #+#    #+#             */
/*   Updated: 2019/12/14 15:33:13 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# include "s_tetr.h"

void	free_field(char **field, int size);
int		ft_count(t_tetr *list);
int		ft_size_field(t_tetr *list);
char	*init_line(int size);
char	**init_field(int size);

int		hi_x(int *fig);
int		hi_y(int *fig);
int		one_bump(char **field, int *fig);
int		box_bump(int *fig, int size);
int		tetra_bump(char **field, int *fig, int size);

int		ft_intdup(int *dst, int *src);
int		*x_shift(int *list, int x);
int		*y_shift(int *list, int y);
int		*tetra_shift(int *list, int x, int y);

void	tetr_put(char **field, int *fig, char letter);
void	tetr_rem(char **field, int *fig);
int		tetra_solver(char **field, t_tetr *list, int size);
int		tetra_helper(char **field, int *fig, t_tetr *list, int size);
void	tetra_printer(char **field, int size);

int		ft_sravnen(int *line);
int		ft_intcmp(int *s1, int *s2);

void	ft_freelst(t_tetr *list);
t_tetr	*new_el(char letter, int *line);
t_tetr	*add_el(char letter, t_tetr *head, int *line);
t_tetr	*ft_tetr(int fd, char *line);

int		*init_x(int *line);
int		*init_y(int *line);
int		*ft_create(int n);
int		*ft_write(int start, int x, int y, int *str);
int		*ck_fig(int fd, char *line, int *str);

void	ft_error(void);
int		ck_valid_block(int n, char *line);
int		ft_hash(char *line);
int		ft_ck_block(int fd, char *line);

int		ft_lists(int fd, char *line);

#endif
