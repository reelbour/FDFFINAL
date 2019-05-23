/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 07:46:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/21 10:30:03 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_mlx *m, int key)
{
	if (key == Q_KEY && (m->zoom > Z_MIN && m->zoom < Z_MAX))
		m->zoom += 0.2;
	if (key == W_KEY && (m->zoom > Z_MIN && m->zoom < Z_MAX))
		if (m->zoom == Z_MIN + 1)
			m->zoom = 0.2;
		else
			m->zoom -= 0.2;
	m->sx = ((W * 0.3) * m->zoom) / (m->nb_w / m->nb_l - 1);
	m->sy = ((H * 0.3) * m->zoom) / (m->nb_l - 1);
}

void	move_arrow(t_mlx *m, int key)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == UP_KEY)
		m->dy -= 75;
	if (key == DOWN_KEY)
		m->dy += 75;
	if (key == LEFT_KEY)
		m->dx -= 75;
	if (key == RIGHT_KEY)
		m->dx += 75;
	if (key == Q_KEY || key == W_KEY)
		zoom(m, key);
	draw(m);
}

int		deal_key(int key, void *param)
{
	if (key == ESC_KEY)
		exit(1);
	if ((key >= LEFT_KEY && key <= DOWN_KEY) || key == Q_KEY || key == W_KEY)
		move_arrow(param, key);
	//ft_putnbr(key);
	return (0);
}
