/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/26 17:23:25 by ahammou-         ###   ########.fr       */
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

/*
** Initializes all parameters in map struct
*/

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	int i = 0;
	int j;

	if (!(map = (t_map*)malloc(sizeof(t_map*))))
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
	}
	free_map(map);
	return (0);
}
