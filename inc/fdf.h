/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/04/30 15:08:38 by ahammou-         ###   ########.fr       */
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
	char	**split;
	int		nb_line;
	int		nb_word;
	int		**coord;
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

// 
// 0 1 2 1 2 12 1 2 112\n
// char **nombre {"0" ,"1" ,"2" ,"1" ,"2" ,"12" ,"1" ,"2" ,"112"};
// nombre[0][0] = "0";
// nombre[1] = "1"
// nombre[dernier] = "112"
//
// atoi(nombre[dernier][0]) 1
//
// int **count_wordd
//
// {
// {10,10,12,13},
// {15,1687,1351},
// {54165},
// }
//
// count_word[0] = {10,10,12,13}
// count_word[0][1] = 10
// count_word[i][j] = atoi(nombre[dernier])//10
// 0 1 45 1 5 55 4 45 45\n
