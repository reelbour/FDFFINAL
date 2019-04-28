/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/28 14:16:39 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes all parameters in map struct
*/

void	init_map(t_map *map)
{
	map->line = NULL;
	map->tab = NULL;
	map->split = NULL;
	map->coord = NULL;
	map->nb_line = 0;
	map->nb_word = 0;
}

/*
** Free all struct params end the struct
*/

void	free_map(t_map *map)
{
	free(map->line);
	free(map->tab);
	free(*map->split);
	free(&*map->split);
	free(map);
}

/*
** Reads a map file and stores the digits in a char *tab
*/

void	read_map(int fd, t_map *map)
{
	int	start;

	start = 0;
	while (get_next_line(fd, &map->line) > 0)
	{
		map->nb_line++;;
		if (start == 0)
		{
			map->tab = ft_strdup(map->line);
			start = 1;
		}
		else
		{
			map->tab = ft_strjoin(map->tab, map->line);
		}
		map->tab = ft_strjoin(map->tab, "\n");
	}
	//printf("%s", map->tab);
}
