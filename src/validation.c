/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:47:01 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/28 18:06:14 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Displays error messages
*/

void	ft_error(int n)
{
	if (n == 1)
	{
		ft_putstr("Couldn't read the fd");
		exit(0);
	}
	if (n == 2)
	{
		ft_putstr("Couldn't allocate memory");
		exit(0);
	}
	if (n == 3)
	{
		ft_putstr("Error");
		exit(0);
	}
}

int		count_nb_char(t_map *map)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] == '\n')
			break ;
		map->nb_char++;
		i++;
	}
	printf("%d\n", map->nb_char * map->nb_line);
	return (map->nb_char);
}
