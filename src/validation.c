/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/06/05 11:10:51 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Check if file is .fdf
*/

void	valid_extension(char *av)
{
	if (!ft_strstr(av, ".fdf"))
	{
		ft_putendl("Error: not a valid file");
		exit(0);
	}
}

/*
** Deals with malloc error
*/

void	ft_error_free(int nb, void **ptr)
{
	if (nb == 2)
	{
		ft_putendl("Error : malloc failure");
		ft_free_tab(ptr);
		exit(0);
	}
}

/*
** Deals with fd errors and valid map datas
*/

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("Error : can't open the file descriptor");
	if (nb == 2)
		ft_putendl("Error : can't read the file descriptor");
	if (nb == 3)
		ft_putendl("Error: the file is empty");
	if (nb == 4)
		ft_putendl("Error: need at least 2 digits(spaced) to draw a segment");
	if (nb == 5)
		ft_putendl("Error: map must be square or rectangle only");
	if (nb == 6)
		ft_putendl("Error: not a valid map");
	exit(0);
}
