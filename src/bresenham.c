/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/12 17:04:02 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_ml(t_ml *ml)
{
	ml->mlx_ptr = mlx_init();
	ml->win_ptr = mlx_new_window(ml->mlx_ptr, W, H, "test");
}

void	init_v(t_v *v, t_m *m)
{
	v->x1 = 50 + m->x;
	v->x2 = 50 + m->x;
	v->y1 = 50 + m->y;
	v->y2 = 50 + m->y;
	v->dx = v->x2 - v->x1;
	v->dy = v->y2 - v->y1;
	v->xinc = (v->dx > 0) ? 1 : -1;
	v->yinc = (v->dy > 0) ? 1 : -1;
	v->dx = ft_abs(v->dx);
	v->dy = ft_abs(v->dy);
}

void line(t_v *v, t_m *m, t_ml *ml)
{
	printf("%s\n", "check if seg here");
	int	cumul;
	int	i;

	m->x = v->x1;
	m->y = v->y1;
	printf("%s\n", "or here");
	init_v(v, m);
	printf("%s\n", "or maybe here");
	mlx_pixel_put(&(ml->mlx_ptr), &(ml->win_ptr), m->x, m->y, 0xFFFFFF);
	printf("%s\n", "just to check after putpx");
	if (v->dx > v->dy)
	{
		cumul = v->dx / 2;
		for (i = 1; i <= v->dx; i++)
		{
			printf("%s\n", "or  maybe in the 1st loop");
			m->x += v->xinc;
			cumul += v->dy;
			if (cumul >= v->dx)
			{
				cumul -= v->dx;
				m->y += v->yinc;
			}
			printf("%s\n", "or at the end of 1st loop before putpx");
			mlx_pixel_put(&(ml->mlx_ptr), &(ml->win_ptr), m->x, m->y, 0xFFFFFF);
			printf("%s\n", "after 2nd putpx");
		}
	}
	else
	{
		cumul = v->dy / 2;
		for (i = 1; i <= v->dy; i++)
		{
			printf("%s\n", "or else in the second  loop");
			m->y += v->yinc;
			cumul += v->dx;
			if (cumul >= v->dy)
			{
				cumul -= v->dy;
				m->x += v->xinc;
			}
			mlx_pixel_put(&(ml->mlx_ptr), &(ml->win_ptr), m->x, m->y, 0xFFFFFF);
		}
	}
}

void	render_m(t_m *m)
{
	t_ml	*ml;
	t_v		*v;
	int i = 0;

	if (!(v = (t_v*)malloc(sizeof(*v))))
		ft_error(2);
	init_ml(ml);
	init_v(v, m);
	while (i < m->nb_l)
	{
		line(v, m, ml);
		i++;
	}

	mlx_loop(ml->mlx_ptr);
}
