/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/30 15:41:01 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	int i = 0;

	if (ac != 2)
		ft_putchar('\n');
	else
	{
		if (!(fd = open(av[1], O_RDONLY)) && fd < 0)
			ft_error(1);
		if (!(map = (t_map*)malloc(sizeof(*map))))
			ft_error(2);
		init_map(map);
		read_map(fd, map);
	}
	//printf("%s\n", map->split);
	return (0);
}
