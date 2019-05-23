/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 07:46:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/23 17:09:09 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_mlx *m, int key)
{
	if (key == PLUS_KEY && (m->zoom < Z_MAX))
		m->zoom += 0.02;
	if (key == MINUS_KEY && (m->zoom > Z_MIN))
		m->zoom -= 0.02;
	m->sx = ((W * 0.3) * m->zoom) / (m->nb_w / m->nb_l - 1);
	m->sy = ((H * 0.3) * m->zoom) / (m->nb_l - 1);
}

void	altitude(t_mlx *m, int key)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == Q_KEY && (m->z < A_MAX))
		m->z -= 0.2;
	if (key == A_KEY && (m->z > A_MIN))
		m->z += 0.2;
	draw(m);
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
	if (key == PLUS_KEY || key == MINUS_KEY)
		zoom(m, key);
	draw(m);
}

void	draw_string(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 5, 10, 0xFFFFFF, "WELCOME ON THIS FDF");
	mlx_string_put(m->mlx, m->win, 5, 35, 0xFFFFFF, "By Ahammou- and Reelbour");
	mlx_string_put(m->mlx, m->win, 5, 100, 0xFFFFFF, "COMMANDS:");
	mlx_string_put(m->mlx, m->win, 5, 115, 0xFFFFFF, "=======================");
	mlx_string_put(m->mlx, m->win, 5, 140, 0xFFFFFF, "Move : arrows < ^ >");
	mlx_string_put(m->mlx, m->win, 5, 165, 0xFFFFFF,
		"Altitude : q(up),a(down)");
	mlx_string_put(m->mlx, m->win, 5, 190, 0xFFFFFF, "Zoom : + and -");
}

int		deal_key(int key, void *param)
{
	if (key == ESC_KEY)
		exit(1);
	if ((key >= LEFT_KEY && key <= UP_KEY) || key == PLUS_KEY
		|| key == MINUS_KEY)
		move_arrow(param, key);
	if (key == Q_KEY || key == A_KEY)
		altitude(param, key);
	ft_putnbr(key);
	return (0);
}
