/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 07:46:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/19 08:33:15 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	deal_key(int key, void *param)
{
	ft_putnbr(key);
	return (0);
}

int	deal_mouse(int scroll, void *param)
{
	ft_putnbr(scroll);
	return (0);
}
