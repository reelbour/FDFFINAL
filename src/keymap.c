/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 07:46:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/27 17:14:35 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	switch_projection(t_mlx *m, int key)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == 18)
		m->p = 1;
	if (key == 19)
		m->p = 2;
	draw(m);
}

void	zoom(t_mlx *m, int key)
{
	if (key == PLUS_KEY && (m->zoom < Z_MAX))
		m->zoom += 0.15;
	if (key == MINUS_KEY && (m->zoom > Z_MIN))
		m->zoom -= 0.15;
	if (m->zoom == 0)
		m->zoom += 0.55;
	m->sx = round(((W * 0.6) / (m->nb_w / m->nb_l)) * m->zoom);
	m->sy = round(((W * 0.6) / (m->nb_w / m->nb_l)) * m->zoom);
}

void	altitude(t_mlx *m, int key)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == Q_KEY && (m->z < A_MAX))
		m->z -= 0.12;
	if (key == A_KEY && (m->z > A_MIN))
		m->z += 0.12;
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

int		deal_key(int key, void *param)
{
	if (key == ESC_KEY)
		exit(1);
	if ((key >= LEFT_KEY && key <= UP_KEY) || key == PLUS_KEY
		|| key == MINUS_KEY)
		move_arrow(param, key);
	if (key == Q_KEY || key == A_KEY)
		altitude(param, key);
	if (key == 18 || key == 19)
		switch_projection(param, key);
	ft_putnbr(key);
	return (0);
}
