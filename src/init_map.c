/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/26 17:05:11 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes all parameters in map struct
*/

void	init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->line = NULL;
	map->tab = NULL;
	map->split = NULL;
	map->tabint = NULL;

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
		if (start == 0)
		{
			if (!(map->tab = ft_strdup(map->line)))
				ft_error(1);
			start = 1;
		}
		else
		{
			if (!(map->tab = ft_strjoin(map->tab, map->line)))
				ft_error(1);
		}
		if (!(map->tab = ft_strjoin(map->tab, "\n")))
			ft_error(1);
	}
	printf("%s", map->tab);
}
