/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/22 17:31:17 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

t_dot	rasterize_para(t_mlx *m, int x, int y, int z)
{
	t_dot		tabxy;

	tabxy.x = m->dx + x + z * m->z;
	tabxy.y = m->dy + y + z * m->z;
	return (tabxy);
}

void	draw_m_para(t_mlx *m, int x, int y)
{
	t_dot	tabxy;

	m->z = -0.0;
	tabxy = rasterize_para(m, x, y, m->coord[y / m->sy][x / m->sx]);
	if (x / m->sx < (m->nb_w / m->nb_l) && y / m->sy < m->nb_l)
		draw_line(m, tabxy,
			m->dx + (x + m->sx) + m->coord[y / m->sy][x / m->sx + 1] * m->z,
			m->dy + y + m->coord[y / m->sy][x / m->sx + 1] * m->z);
	if (y / m->sy < m->nb_l - 1 && x / m->sx < m->nb_w / m->nb_l)
		draw_line(m, tabxy,
			m->dx + x + m->coord[y / m->sy + 1][x / m->sx] * m->z,
			m->dy + (y + m->sy) + m->coord[y / m->sy + 1][x / m->sx] * m->z);
	if (x / m->sx == (m->nb_w / m->nb_l) && y / m->sy < m->nb_l - 1)
		draw_line(m, tabxy,
			m->dx + x + m->coord[y / m->sy + 1][x / m->sx] * m->z,
			m->dy + (y + m->sy) + m->coord[y / m->sy + 1][x / m->sx] * m->z);
}

t_dot	rasterize_iso(t_mlx *m, int x, int y, int z)
{
	t_dot		tabxy;

	tabxy.x = m->dx + (x - y);
	tabxy.y = m->dy + z * m->z + x + y;
	return (tabxy);
}

void	draw_m_iso(t_mlx *m, int x, int y)
{
	t_dot	tabxy;

	tabxy = rasterize_iso(m, x, y, m->coord[y / m->sy][x / m->sx]);
	if (x / m->sx < (m->nb_w / m->nb_l) && y / m->sy < m->nb_l)
		draw_line(m, tabxy, m->dx + ((x + m->sx) - y), m->dy +
		m->coord[y / m->sy][x / m->sx + 1] * m->z + (x + m->sx) + y);
	if (x / m->sx == (m->nb_w / m->nb_l) && y / m->sy < m->nb_l - 1)
		draw_line(m, tabxy, m->dx + (x - (y + m->sy)), m->dy +
		m->coord[y / m->sy + 1][x / m->sx] * m->z + x + (y + m->sy));
	if (y / m->sy < m->nb_l - 1 && x / m->sx < m->nb_w / m->nb_l)
		draw_line(m, tabxy, m->dx + (x - (y + m->sy)), m->dy +
		m->coord[y / m->sy + 1][x / m->sx] * m->z + x + (y + m->sy));
}

void	init_draw(t_mlx *m)
{
	if (m->check == 0)
	{
		m->z = -3;
		m->dx = W * 0.4;
		m->dy = 50;
		m->sx = (W * 0.3) / (m->nb_w / m->nb_l - 1);
		m->sy = (H * 0.3) / (m->nb_l - 1);
		m->clr = 0x00FFFF;
	}
	m->check++;
}

void	draw(t_mlx *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_draw(m);
	while (x / m->sx < (m->nb_w / m->nb_l) || y / m->sy < m->nb_l - 1)
	{
		if (x / m->sx == (m->nb_w / m->nb_l))
		{
			x = 0;
			y += m->sy;
		}
		draw_m_para(m, x, y);
		//mlx_pixel_put(m->mlx, m->win, x, y, 0xFFFFFF);
		x += m->sx;
		if (x / m->sx == (m->nb_w / m->nb_l))
		{
			draw_m_para(m, x, y);
			//mlx_pixel_put(m->mlx, m->win, x, y, 0xFFFFFF);
		}
	}
}

void	render_m(t_mlx *m)
{
	if (!(m->mlx = ft_memalloc(sizeof(m->mlx))))
		return ;
	if (!(m->win = ft_memalloc(sizeof(m->win))))
		return ;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "test");
	draw(m);
	mlx_key_hook(m->win, deal_key, (void*)m);
	// printf("%s%d\n", "m->nb_w : ", m->nb_w);
	// printf("%s%d\n", "m->nb_l : ", m->nb_l);
	// printf("%s%d\n", "m->z : ", m->z);
	// printf("%s%d\n", "m->dx : ", m->dx);
	// printf("%s%d\n", "m->dy : ", m->dy);
	// printf("%s%d\n", "m->sx : ", m->sx);
	// printf("%s%d\n", "m->sy : ", m->sy);
	// printf("%s%d\n", "m->x0 : ", m->x0);
	// printf("%s%d\n", "m->y0 : ", m->y0);
	mlx_loop(m->mlx);
}
