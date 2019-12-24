/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tetr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:44:13 by etristan          #+#    #+#             */
/*   Updated: 2019/12/14 15:06:29 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TETR_H
# define S_TETR_H

# define I_TETR (int [8]) {0,0,0,1,0,2,0,3}
# define IH_TETR (int [8]) {0,0,1,0,2,0,3,0}
# define O_TETR (int [8]) {0,0,1,0,0,1,1,1}
# define L_TETR (int [8]) {0,0,0,1,0,2,1,2}
# define LR_TETR (int [8]) {0,0,1,0,2,0,0,1}
# define LD_TETR (int [8]) {0,0,1,0,1,1,1,2}
# define LL_TETR (int [8]) {2,0,0,1,1,1,2,1}
# define J_TETR (int [8]) {1,0,1,1,0,2,1,2}
# define JR_TETR (int [8]) {0,0,0,1,1,1,2,1}
# define JD_TETR (int [8]) {0,0,1,0,0,1,0,2}
# define JL_TETR (int [8]) {0,0,1,0,2,0,2,1}
# define T_TETR (int [8]) {1,0,0,1,1,1,2,1}
# define TR_TETR (int [8]) {0,0,0,1,1,1,0,2}
# define TD_TETR (int [8]) {0,0,1,0,2,0,1,1}
# define TL_TETR (int [8]) {1,0,0,1,1,1,1,2}
# define S_TETR (int [8]) {1,0,2,0,0,1,1,1}
# define SR_TETR (int [8]) {0,0,0,1,1,1,1,2}
# define Z_TETR (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_TETR (int [8]) {1,0,0,1,1,1,0,2}

typedef struct		s_tetr
{
	char			name;
	int				*str;
	struct s_tetr	*next;
}					t_tetr;

#endif
