/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/28 18:06:09 by ahammou-         ###   ########.fr       */
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
	map->nb_line = 0;
	map->nb_char = 0;
}

/*
** Reads a map file and stores the digits in a char *tab
*/

void	read_map(int fd, t_map *map)
{
	int	start;
	int	nb_char_init;

	start = 0;
	nb_char_init = 0;
	while (get_next_line(fd, &map->line) > 0)
	{
		map->nb_line++;
		//verif
		(nb_char_init == 0) ? count_nb_char(map->line) : nb_char_init;
		if (start == 0)
		{
			map->tab = ft_strdup(map->line);
			start = 1;
		}
		else
			map->tab = ft_strjoin(map->tab, map->line);
		map->tab = ft_strjoin(map->tab, "\n");
		(nb_char_init != count_nb_char(map)) ? ft_error(3) : continue ; 
	}
}
