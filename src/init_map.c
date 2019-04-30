/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/30 15:48:30 by ahammou-         ###   ########.fr       */
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
	map->nb_word = 0;
	map->coord = 0;
}

void	stock_int(t_map *map)
{
	int	i;

	i = 0;
	map->split = (char**)malloc((sizeof(char) * map->nb_word) * map->nb_line);
	map->coord = (int**)malloc(sizeof(int *) * map->nb_line);
	map->split = ft_strsplit(map->str, '\n');
	// printf("nbword %d|%d\n", map->nb_word, (int)ft_strlen(nombre[0]));
	while (map->split[i])
	{

		char **nombre = ft_strsplit(map->split[i], ' ');
		map->coord[i] = (int *)malloc(sizeof(map->nb_word / map->nb_line));
		int j = 0;
		while (j < (map->nb_word / map->nb_line))
		{
			//printf("[%i]: %d ",j, ft_atoi(nombre[j]));
			map->coord[i][j] = ft_atoi(nombre[j]);
			printf("map->coord[%d][%d]: |%d|\n", i, j, map->coord[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
		if (start == 0)
		{
			map->str = ft_strdup(map->line);
			start = 1;
		}
		else
			map->str = ft_strjoin(map->str, map->line);
		map->str = ft_strjoin(map->str, "\n");
	}
	map->nb_word = ft_countwords(map->str, ' ') - 1;
	stock_int(map);
}
