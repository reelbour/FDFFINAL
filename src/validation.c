/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/23 14:37:24 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error_free(int nb, void **ptr)
{
	if (nb == 2)
	{
		ft_putendl("malloc failure");
	}
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("can't open the file descriptor");
	if (nb == 3)
		ft_putendl("error");
	exit(0);
}
