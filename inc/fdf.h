/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/04/30 12:04:41 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx/mlx.h"
# include "../lib/gnl/get_next_line.h"
# include <stdio.h>

typedef struct	s_map
{
	char	*line;
	char	*str;
	int		nb_line;
	int		nb_word;
	int		*coord;
}				t_map;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			init_map(t_map *map);
void			read_map(int fd, t_map *map);
int				count_words(char *str);
void			stock_int(t_map *map);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int n);
#endif
