/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/06/05 11:59:07 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initialize structure variables
*/

void	init_draw(t_mlx *m)
{
	if (m->check == 0)
	{
		m->p = 2;
		m->zoom = 0.8;
		m->z = -0.95;
		m->dx = W * 0.4;
		m->dy = 50;
		m->sx = ((W * 0.6) / m->nb_col) * m->zoom;
		m->sy = ((W * 0.6) / m->nb_col) * m->zoom;
		m->clr = 0xFF80ED;
	}
	m->check = 1;
}

/*
** Draw projections
*/

void	draw(t_mlx *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_string(m);
	init_draw(m);
	while (x / m->sx < m->nb_col - 1 || y / m->sy < m->nb_l - 1)
	{
		if (x / m->sx == m->nb_col - 1)
		{
			x = 0;
			y += m->sy;
		}
		choose_projection(m, x, y);
		x += m->sx;
		if (x / m->sx == m->nb_col - 1)
			choose_projection(m, x, y);
	}
}

/*
** Display projections
*/

void	choose_projection(t_mlx *m, int x, int y)
{
	if (m->p == 1)
		draw_m_para(m, x, y);
	if (m->p == 2)
		draw_m_iso(m, x, y);
}

void	render_m(t_mlx *m)
{
	if (!(m->mlx = mlx_init()))
		ft_error_free(2, (void**)m->coord);
	if (!(m->win = mlx_new_window(m->mlx, W, H, "FDF")))
		ft_error_free(2, (void**)m->coord);
	draw(m);
	mlx_key_hook(m->win, deal_key, (void*)m);
	mlx_loop(m->mlx);
	ft_free_tab((void**)m->coord);
	free(&m->mlx);
	free(&m->win);
}
