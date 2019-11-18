/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:44:13 by etristan          #+#    #+#             */
/*   Updated: 2019/10/28 21:49:03 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

typedef struct		s_tetr
{
	char			name;
	int				x;
	int				y;
	struct s_tetr	*next;
}					t_tetr;

#endif
