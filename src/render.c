/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/17 13:30:05 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_lines(t_mlx *m, int x, int y)
{
	int t_xy[2];

	t_xy[0] = m->dx + (x - y);
	t_xy[1] = m->dy + m->coord[y / m->sy][x / m->sx] * m->z + x + y;
	if (x / m->sx < (m->nb_w / m->nb_l) - 1 && y / m->sy < m->nb_l)
		draw_line(m, t_xy, m->dx + ((x + m->sx) - y),
		m->dy + m->coord[y / m->sy][x / m->sx] * m->z + (x + m->sx) + y);
	if (y / m->sy < m->nb_l - 1 && x / m->sx < (m->nb_w / m->nb_l))
		draw_line(m, t_xy, m->dx + (x - (y + m->sy)),
		m->dy + m->coord[y / m->sy + 1][x / m->sx] * m->z + (y + m->sy));
}

void	init_draw(t_mlx *m)
{
	if (m->check == 0)
	{
		m->z = -5;
		m->dx = W * 0.4;
		m->dy = 20;
		m->sx = (W * 0.7) / ((m->nb_w / m->nb_l) - 1);
		m->sy = (H * 0.5) / (m->nb_l - 1);
		m->clr = 0xFFFFFF;
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
	printf("%s%d\n", "m->nb_w : ", m->nb_w);
	printf("%s%d\n", "m->nb_l : ", m->nb_l);
	printf("%s%d\n", "m->z : ", m->z);
	printf("%s%d\n", "m->dx : ", m->dx);
	printf("%s%d\n", "m->dy : ", m->dy);
	printf("%s%d\n", "m->sx : ", m->sx);
	printf("%s%d\n", "m->sy : ", m->sy);
	printf("%s%d\n", "m->x0 : ", m->x0);
	printf("%s%d\n", "m->y0 : ", m->y0);
	printf("%s%d\n", "m->x1 : ", m->x1);
	printf("%s%d\n", "m->y1 : ", m->y1);
	printf("%s%d\n", "m->e : ", m->e);
	mlx_loop(m->mlx);
}
