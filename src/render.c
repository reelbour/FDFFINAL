/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/23 16:52:12 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initialize structure variables **
*/

void	init_draw(t_mlx *m)
{
	if (m->check == 0)
	{
		m->zoom = 0.8;
		m->z = -2;
		m->dx = W * 0.4;
		m->dy = 250;
		m->sx = ((W * 0.3) / (m->nb_w / m->nb_l - 1)) * m->zoom;
		m->sy = ((H * 0.3) / (m->nb_l - 1)) * m->zoom;
		m->clr = 0x00FFFF;
	}
	m->check++;
}

/*
** Draw projections **
*/

void	draw(t_mlx *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_string(m);
	init_draw(m);
	while (x / m->sx < (m->nb_w / m->nb_l) || y / m->sy < m->nb_l - 1)
	{
		if (x / m->sx == (m->nb_w / m->nb_l))
		{
			x = 0;
			y += m->sy;
		}
		draw_m_para(m, x, y);
		x += m->sx;
		if (x / m->sx == (m->nb_w / m->nb_l))
		{
			draw_m_para(m, x, y);
		}
	}
}

/*
** Display projections **
*/

void	render_m(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "FDF");
	draw(m);
	mlx_key_hook(m->win, deal_key, (void*)m);
	mlx_loop(m->mlx);
	ft_free_tab_void(&m->mlx);
	ft_free_tab_void(&m->win);
}
