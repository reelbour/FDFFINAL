/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/28 14:26:06 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

/*
** Displays errors messages
*/

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr("Erreur de lecture du fd");
	if (n == 2)
		ft_putstr("Erreur d'allocations memoire");
}
int		count_word(t_map *map)
{
	int i;

	i = 0;
	while (map->str[i] != ' ' || map->str[i] != '\n')


}

void	convert_int_tab(t_map *map)
{
	int i = 0;
	int k = 0;

	while (map->split[i])
	{
		if (map->split[i] == '\n')
			i++;
		else
		{
			map->coord[k] = ft_atoi(map->split[i]);
			i++;
			k++;
		}
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	int i = 0;

	if (!(map = (t_map*)malloc(sizeof(*map))))
		ft_error(2);
	if (!(fd = open(av[1], O_RDONLY)) && fd < 0)
		ft_error(1);
	if (ac != 2)
		ft_putchar('\n');
	else
	{
		init_map(map);
		read_map(fd, map);
		map->split = ft_strsplit(map->tab, ' ');
		/*while (map->split[i])
		{
			printf("%s", map->split[i]);
			i++;
		}
		printf("%d\n", map->nb_line);*/
	}
	//free_map(map);
	return (0);
}
