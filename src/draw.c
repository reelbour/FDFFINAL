/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:50:46 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/28 17:49:25 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Bresenham algorithm **
*/

void	draw_line(t_mlx *m, t_dot tabxy, int x, int y)
{
	t_dot	tabxy_s;
	t_dot	tabxy_e;
	int		e[2];

	m->x0 = tabxy.x;
	m->y0 = tabxy.y;
	tabxy_s.x = abs(x - m->x0);
	tabxy_e.x = m->x0 < x ? 1 : -1;
	tabxy_s.y = abs(y - m->y0);
	tabxy_e.y = m->y0 < y ? 1 : -1;
	e[0] = (tabxy_s.x > tabxy_s.y ? tabxy_s.x : -tabxy_s.y) / 2;
	while (m->x0 != x || m->y0 != y)
	{
		mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, m->clr);
		e[1] = e[0];
		e[1] > -tabxy_s.x ? e[0] -= tabxy_s.y : 1 == 1;
		e[1] > -tabxy_s.x ? m->x0 += tabxy_e.x : 1 == 1;
		e[1] < tabxy_s.y ? e[0] += tabxy_s.x : 1 == 1;
		e[1] < tabxy_s.y ? m->y0 += tabxy_e.y : 1 == 1;
	}
}

/*
** formula for isometric projection **
*/

t_dot	rasterize_iso(t_mlx *m, int x, int y, int z)
{
	t_dot		tabxy;

	tabxy.x = m->dx + ((0.7 * (double)x) - (0.7 * (double)y));
	tabxy.y = m->dy + z * m->z + ((0.7 / 2.0) * (double)x + (0.7 / 2.0)
	* (double)y);
	return (tabxy);
}

void	draw_m_iso(t_mlx *m, int x, int y)
{
	t_dot	tabxy;

	tabxy = rasterize_iso(m, x, y, m->coord[y / m->sy][x / m->sx]);
	if (x / m->sx < (m->nb_w / m->nb_l) && y / m->sy < m->nb_l)
		draw_line(m, tabxy,
			m->dx + 0.7 * (double)(x + m->sx) - 0.7 * (double)y,
			m->dy + m->coord[y / m->sy][x / m->sx + 1] * m->z + (0.7 / 2.0) * (x + m->sx) + (0.7 / 2.0) * y);
	if (x / m->sx == (m->nb_w / m->nb_l) && y / m->sy < m->nb_l - 1)
		draw_line(m, tabxy,
			m->dx + 0.7 * (double)x - 0.7 * (double)(y + m->sy),
			m->dy + m->coord[y / m->sy + 1][x / m->sx] * m->z + (0.7 / 2.0) * x + (0.7 / 2.0) * (y + m->sy));
	if (y / m->sy < m->nb_l - 1 && x / m->sx < m->nb_w / m->nb_l)
		draw_line(m, tabxy,
			m->dx + 0.7 * (double)x - 0.7 * (double)(y + m->sy),
			m->dy + m->coord[y / m->sy + 1][x / m->sx] * m->z + (0.7 / 2.0) * x + (0.7 / 2.0) * (y + m->sy));
}

/*
** formula for parallel porjection **
*/

t_dot	rasterize_para(t_mlx *m, int x, int y, int z)
{
	t_dot		tabxy;

	tabxy.x = m->dx + x + 0.7 * (z * m->z);
	tabxy.y = m->dy + y + (0.7 / 2) * (z * m->z);
	return (tabxy);
}

void	draw_m_para(t_mlx *m, int x, int y)
{
	t_dot	tabxy;

	tabxy = rasterize_para(m, x, y, m->coord[y / m->sy][x / m->sx]);
	if (x / m->sx < (m->nb_w / m->nb_l) && y / m->sy < m->nb_l)
		draw_line(m, tabxy,
			m->dx + (x + m->sx) + 0.7 * (m->coord[y / m->sy][x / m->sx + 1] * m->z),
			m->dy + y + (0.7 / 2) * (m->coord[y / m->sy][x / m->sx + 1] * m->z));
	if (y / m->sy < m->nb_l - 1 && x / m->sx < m->nb_w / m->nb_l)
		draw_line(m, tabxy,
			m->dx + x + 0.7 * (m->coord[y / m->sy + 1][x / m->sx] * m->z),
			m->dy + (y + m->sy) + (0.7 / 2) * (m->coord[y / m->sy + 1][x / m->sx] * m->z));
	if (x / m->sx == (m->nb_w / m->nb_l) && y / m->sy < m->nb_l - 1)
		draw_line(m, tabxy,
			m->dx + x + 0.7 * (m->coord[y / m->sy + 1][x / m->sx] * m->z),
			m->dy + (y + m->sy) + (0.7 / 2) * (m->coord[y / m->sy + 1][x / m->sx] * m->z));
}
