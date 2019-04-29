/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/29 17:57:45 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
 ** Initializes all parameters in map struct
 */

void	init_map(t_map *map)
{
	map->line = NULL;
	map->str = NULL;
	map->nb_line = 0;
	map->coord = 0;
}

void		save_coord(t_map *map)
{
	map->coord = ft_atoi(map->str);
}

/*
 ** Reads a map file and stores the digits in a int **tab
 */

void	read_map(int fd, t_map *map)
{
	int	start;

	start = 0;
	while (get_next_line(fd, &map->line) > 0)
	{
		map->nb_line++;
		if (start == 0 && map->line)
		{
			map->str = ft_strdup(map->line);
			start = 1;
		}
		else
			map->str = ft_strjoin(map->str, map->line);
		map->str = ft_strjoin(map->str, "\n");
	}
	save_coord(map);
}
//		if (!(map->split = ft_strsplit(map->line, ' ')))
//			ft_error(2);
//	if (!(map->nb = (int**)malloc(sizeof(int*) * map->nb_line)) &&
//			!(map->nb_split = (int*)malloc(sizeof(int) * map->nb_line)))
//		ft_error(2);
