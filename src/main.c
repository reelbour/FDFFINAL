/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/06/02 13:03:29 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_mlx	*m;

	if (ac != 2)
		ft_putendl("Usage: ./fdf must be followed by a file.fdf");
	else
	{
		valid_extension(av[1]);
		if (!(fd = open(av[1], O_RDONLY)) && fd < 0)
			ft_error(1);
		if (!(m = ft_memalloc(sizeof(*m))))
			ft_error_free(2, (void**)&m);
		read_m(fd, m);
		close(fd);
		render_m(m);
		free(m);
	}
	return (0);
}
