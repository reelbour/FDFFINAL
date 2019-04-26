/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/04/26 17:01:26 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx/mlx.h"
# include "../lib/gnl/get_next_line.h"
# include <stdio.h>

/*
** tab [x}[y] = z;
*/

typedef struct	s_map
{
	char	*tab;
	char	**split;
	int		x;
	int		y;
	int		z;
	char	*line;
}				t_map;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			init_map(t_map *map);
void			read_map(int fd, t_map *map);
void			free_map(t_map *map);

#endif
