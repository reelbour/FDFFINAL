/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 07:46:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/20 16:50:48 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_mlx *m, int key)
{
	return ;
}

void	move_arrow(t_mlx *m, int key)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == 126)
		m->dy -= 50;
	if (key == 125)
		m->dy += 50;
	if (key == 123)
		m->dx -= 50;
	if (key == 124)
		m->dx += 50;
	draw(m);
}

int		deal_key(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (key > 122 && key < 127)
		move_arrow(param, key);
	if (key == 91 || key == 84)
		zoom(m, key);
	return (0);
}
