/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/19 08:45:11 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_line(t_mlx *m, int *tabxy, int x, int y)
{
	int		tabx[2];
	int		taby[2];
	int		e[2];

	m->x0 = tabxy[0];
	m->y0 = tabxy[1];
	tabx[0] = abs(x - m->x0);
	tabx[1] = m->x0 < x ? 1 : -1;
	taby[0] = abs(y - m->y0);
	taby[1] = m->y0 < y ? 1 : -1;
	e[0] = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (m->x0 != x || m->y0 != y)
	{
		mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, m->clr);
		e[1] = e[0];
		e[1] > -tabx[0] ? e[0] -= taby[0] : 1 == 1;
		e[1] > -tabx[0] ? m->x0 += tabx[1] : 1 == 1;
		e[1] < taby[0] ? e[0] += tabx[0] : 1 == 1;
		e[1] < taby[0] ? m->y0 += taby[1] : 1 == 1;
	}
}

void	draw_lines(t_mlx *m, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = m->dx + (x - y);
	tabxy[1] = m->dy + m->coord[y / m->sy][x / m->sx] * m->z
		+ x + y;
	if (x / m->sx < (m->nb_w / m->nb_l) - 1 && y / m->sy < m->nb_l)
		draw_line(m, tabxy, m->dx + ((x + m->sx) - y),
		m->dy + m->coord[y / m->sy][x / m->sx + 1] * m->z +
		(x + m->sx) + y);
	if (y / m->sy < m->nb_l - 1 && x / m->sx < (m->nb_w / m->nb_l))
		draw_line(m, tabxy, m->dx + (x - (y + m->sy)),
		m->dy + m->coord[y / m->sy + 1][x / m->sx] * m->z +
		x + (y + m->sy));
}

void	init_draw(t_mlx *m)
{
	if (m->check == 0)
	{
		m->z = -5;
		m->dx = W * 0.4;
		m->dy = 20;
		m->sx = (W * 0.7) / (m->nb_w / m->nb_l - 1);
		m->sy = (H * 0.5) / (m->nb_l - 1);
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
	while (x / m->sx < (m->nb_w / m->nb_l) - 1 || y / m->sy < m->nb_l - 1)
	{
		if (x / m->sx == (m->nb_w / m->nb_l))
		{
			x = 0;
			y += m->sy;
		}
		draw_lines(m, x, y);
		x += m->sx;
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
	mlx_key_hook(m->win, deal_key, (void*)0);
	mlx_mouse_hook(m->win, deal_mouse, (void*)0);
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
