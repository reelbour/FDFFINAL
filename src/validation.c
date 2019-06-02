/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/06/02 14:30:17 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		valid_format(char *str)
{
	ft_atoi(str);
	// int res;
	// int i;
	//
	// res = 0;
	// i = 0;
	// while (str[i])
	// {
	// 	if (str[i] < 48 && str[i] > 57)
	// 		ft_error
	// }
	// return (res);
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
		ft_putendl("Error: the file is empty");
	if (nb == 4)
		ft_putendl("Error: need at least 2 digits(spaced) per line to draw a\
			segment with less than 502 lines");
	if (nb == 5)
		ft_putendl("Error: map must be square or rectangle only");
	if (nb == 6)
		ft_putendl("Error: not a valid map");
	exit(0);
}
