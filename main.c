/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/30 20:04:21 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"
#include "lib/minilibx/mlx.h"

int		main(int ac, char **av)
{
	int		fd;
	t_m		*m;

	if (ac != 2)
		ft_putchar('\n');
	else
	{
		if (!(fd = open(av[1], O_RDONLY)) && fd < 0)
			ft_error(1);
		if (!(m = (t_m*)malloc(sizeof(*m))))
			ft_error(2);
		init_m(m);
		read_m(fd, m);
		m->mlx = mlx_init();
		m->win = mlx_new_window(m->mlx, 1280, 900, "FDF");
		mlx_loop(m->mlx);

	}
	//ft_free_tab((void**)m->split);
	return (0);
}
