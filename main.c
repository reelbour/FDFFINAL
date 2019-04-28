/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/28 16:15:18 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

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
	}
	return (0);
}
