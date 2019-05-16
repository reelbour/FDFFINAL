/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/13 12:48:26 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// void TraceSegmentTL(t_v *v, t_ml *ml)
// {
// 	v->dx = v->x1 - v->x0;
// 	v->dy = v->y1 - v->y0;
// 	v->dp = 2 * v->dy - v->dx; /* Valeur initiale de v->dp */
// 	v->delta_e = 2 * v->dy;
// 	v->delta_ne = 2 * (v->dy - v->dx);
// 	int	x = v->x0;
// 	int y = v->y0;
//
// 	mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	while (x < v->x1)
// 	{
// 		if (v->dp <= 0)
// 		{
// 			v->dp = v->dp + v->delta_e;
// 			x++;
// 		}
// 		else
// 		{
// 			v->dp = v->dp + v->delta_ne;
// 			x++;
// 			y++;
// 		}
// 		mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	}
// }
//
// void TraceSegmentTR(t_v *v, t_ml *ml)
// {
// 	v->dx = v->x1 - v->x0;
// 	v->dy = v->y1 - v->y0;
// 	int v->dp = 2 * v->dy - v->dx; /* Valeur initiale de v->dp */
// 	int v->delta_e = 2 * v->dy;
// 	int v->delta_ne = 2 * (v->dy - v->dx);
// 	int x = v->x0;
// 	int y = v->y0;
//
// 	mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	while (x < v->x1)
// 	{
// 		if (v->dp <= 0) /* On choisit le point E */
// 		{
// 			v->dp = v->dp + v->delta_e; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			/* y_p+1 = y_p */
// 		}
// 		else /* On choisit le point NE */
// 		{
// 			v->dp = v->dp + v->delta_ne; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			y++; /* Calcul de y_p+1 */
// 		}
// 		mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	}
// }
//
// void TraceSegmentBL(t_v *v, t_ml *ml)
// {
// 	v->dx = v->x1 - v->x0;
// 	v->dy = v->y1 - v->y0;
// 	int v->dp = 2 * v->dy - v->dx; /* Valeur initiale de v->dp */
// 	int v->delta_e = 2 * v->dy;
// 	int v->delta_ne = 2 * (v->dy - v->dx);
// 	int x = v->x0;
// 	int y = v->y0;
//
// 	mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	while (x < v->x1)
// 	{
// 		if (v->dp <= 0) /* On choisit le point E */
// 		{
// 			v->dp = v->dp + v->delta_e; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			/* y_p+1 = y_p */
// 		}
// 		else /* On choisit le point NE */
// 		{
// 			v->dp = v->dp + v->delta_ne; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			y++; /* Calcul de y_p+1 */
// 		}
// 		mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	}
// }
//
// void TraceSegmentBR(t_v *v, t_ml *ml)
// {
// 	v->dx = v->x1 - v->x0;
// 	v->dy = v->y1 - v->y0;
// 	int v->dp = 2 * v->dy - v->dx; /* Valeur initiale de v->dp */
// 	int v->delta_e = 2 * v->dy;
// 	int v->delta_ne = 2 * (v->dy - v->dx);
// 	int x = v->x0;
// 	int y = v->y0;
//
// 	mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	while (x < v->x1)
// 	{
// 		if (v->dp <= 0) /* On choisit le point E */
// 		{
// 			v->dp = v->dp + v->delta_e; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			/* y_p+1 = y_p */
// 		}
// 		else /* On choisit le point NE */
// 		{
// 			v->dp = v->dp + v->delta_ne; /* Nouveau v->dp */
// 			x++; /* Calcul de x_p+1 */
// 			y++; /* Calcul de y_p+1 */
// 		}
// 		mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, x, y, 0xFFFFFF);
// 	}
// }
//
// static void traceSegment(t_v *v, t_ml *ml)
// {
// 	if (v->x1 > v->x0 && v->y1 > v->y0)
// 		TraceSegmentBR(v, ml);
// 	else if (v->x1 > v->x0 && v->y1 < v->y0)
// 		TraceSegmentTR(v, ml);
// 	else if (v->x1 < v->x0 && v->y1 < v->y0)
// 		TraceSegmentTL(v, ml);
// 	else if (v->x1 < v->x0 && v->y1 > v->y0)
// 		TraceSegmentBL(v, ml);
// }

void 	draw_map(t_m *m, t_v *v, t_ml *ml)
{
		int i = 0;
		int x = 50;
		int y = 50;
		//********** center right

		v->y0 = 50;
		v->y1 = 50;

		while (i < m->nb_l)
		{
			int j = 0;
			while (j < m->nb_l)
			{
				v->x1 = v->x0 + 25;
				draw_line(v, ml);
				v->x0 = v->x1;
				j++;
			}
			v->x0 = x;
			i++;
		}
}

void	render_m(t_m *m)
{
	t_ml	*ml;
	t_v		*v;

	if (!(v = (t_v*)malloc(sizeof(*v))))
		ft_error(2);
	if (!(ml = (t_ml*)malloc(sizeof(*ml))))
		ft_error(2);
	//v->x0 = 20;
	//v->y0 = 20;
	ml->mlx_ptr = mlx_init();
	ml->win_ptr = mlx_new_window(ml->mlx_ptr, W, H, "test");
	//testcases(v, ml);
	draw_map(m, v, ml);
	mlx_loop(ml->mlx_ptr);
}
