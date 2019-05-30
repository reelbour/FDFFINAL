/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/30 17:36:11 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		valid_format(char *str)
{
	ft_atoi(str);
	return (1);
}

void	valid_extension(char *av)
{
	if (!ft_strstr(av, ".fdf"))
	{
		ft_putendl("Error: not a valid file");
		exit(0);
	}
}

void	ft_error_free(int nb, void **ptr)
{
	if (nb == 2)
	{
		ft_putendl("Error : malloc failure");
		ft_free_tab_void(ptr);
		exit(0);
	}
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("Error : can't open the file descriptor");
	if (nb == 2)
		ft_putendl("Error : can't read the file descriptor");
	if (nb == 3)
		ft_putendl("Error: the file descriptor is empty");
	if (nb == 4)
		ft_putendl("Error: need at least 4 digits per line");
	if (nb == 5)
		ft_putendl("Error: map must be square or rectangle only");
	if (nb == 6)
		ft_putendl("Error: not a valid map");
	exit(0);
}
