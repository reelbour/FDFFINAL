/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/08 16:30:56 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_v(t_v *v, t_m *m)
{
	v->x0 = ((W / m->nb_l) * 1) + (m->i * V);
	v->x1 = ((W / m->nb_l) * 2) + (m->i * V);
	v->y0 = ((W / m->nb_l) * 1) + (m->j * V);
	v->y1 = ((W / m->nb_l) * 2) + (m->j * V);
	v->dx = ft_abs(v->x1 - v->x0);
	v->dy = ft_abs(v->y1 - v->y0);
	v->ix = (v->x0 < v->x1) ? 1 : -1;
	v->iy = (v->y0 < v->y1) ? 1 : -1;
	v->e = (v->dx > v->dy ? v->dx : ((v->dy) * -1)) / 2;
	v->e2 = 0;
}

void	line(t_v *v, t_m *m, t_ml ml)
{
	init_v(v, m);
	while (1)
	{
		mlx_pixel_put(ml.mlx_ptr, ml.win_ptr, v->x0, v->y0, 0xFFFFFF);
		if (v->x0 == v->x1 && v->y0 == v->y1)
			break ;
		v->e2 = v->e;
		if (v->e2 > ((v->dx) * -1))
		{
			v->e -= v->dy;
			v->x0 += v->ix;
		}
		if (v->e2 < v->dy)
		{
			v->e += v->dx;
			v->y0 += v->iy;
		}
	}
}

void	render_m(t_m *m)
{
	t_ml	ml;
	t_v		*v;

	ml.mlx_ptr = mlx_init();
	ml.win_ptr = mlx_new_window(ml.mlx_ptr, W, H, "test");
	while (m->i <= m->nb_l)
	{
		m->j = 0;
		while (m->j <= m->nb_l)
		{
			//line(v, m, ml);
			init_v(v, m);
			mlx_pixel_put(ml.mlx_ptr, ml.win_ptr, v->x0, v->y0, 0xFFFFFF);
			m->j++;
		}
		m->i++;
	}
	mlx_loop(ml.mlx_ptr);
}
