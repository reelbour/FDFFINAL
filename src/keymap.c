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
	if (key == 69)
		m->zoom += 0.02;
	if (key == 78)
	{
		if (m->zoom > 0.03)
			m->zoom -= 0.02;
	}
	m->sx = round(((W * 0.3) * m->zoom) / (m->nb_w / m->nb_l - 1));
	m->sy = round(((H * 0.3) * m->zoom) / (m->nb_l - 1));

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
	if (key == 69 || key == 78)
		zoom(m, key);
	draw(m);
}

int		deal_key(int key, void *param)
{
	if (key == 53)
		exit(1);
	if ((key > 122 && key < 127) || key == 69 || key == 78)
		move_arrow(param, key);
	return (0);
}
