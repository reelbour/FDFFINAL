/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/04/30 20:06:39 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx/mlx.h"
# include "../lib/gnl/get_next_line.h"
# include <stdio.h>

typedef struct	s_m
{
	int		nb_l;
	int		nb_w;
	int		**coord;
	void	*win;
	void	*mlx;
}				t_m;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			init_m(t_m *m);
void			read_m(int fd, t_m *m);
int				count_words(char *str);
void			stock_int_tab(char *str, t_m *m);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int n);
#endif
