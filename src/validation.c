/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:47:01 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/30 21:09:27 by ahammou-         ###   ########.fr       */
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
		ft_putstr("Error : couldn't read the fd");
		exit(0);
	}
	if (n == 2)
	{
		ft_putstr("Error : couldn't allocate memory");
		exit(1);
	}
	if (n == 3)
	{
		ft_putstr("Error");
		exit(0);
	}
}