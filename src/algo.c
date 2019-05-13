/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:25:52 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/13 12:19:27 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_line(t_v *v, t_ml *ml)
{
	v->dx = v->x1 - v->x0;
	if (v->dx != 0)
	{
		if (v->dx > 0)
		{
			v->dy = v->y1 - v->y0;
			if (v->dy != 0)
			{
				if (v->dy > 0)
				{
					if (v->dx >= v->dy)
					{
						v->e = v->dx;
						v->dx = v->e * 2;
						v->dy = v->dy * 2;
						while (v->x0 < v->x1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->x0++;
							v->e -= v->dy;
							if (v->e <= 0)
							{
								v->y0++;
								v->e += v->dx;
							}
						}
					}
					else
					{
						v->e = v->dy;
						v->dy = v->e * 2;
						v->dx = v->dx * 2;
						while (v->y0 < v->y1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->y0++;
							v->e -= v->dx;
							if (v->e <= 0)
							{
								v->x0++;
								v->e += v->dy;
							}
						}
					}
				}
				else
				{
					if (v->dx >= -v->dy)
					{
						v->e = v->dx;
						v->dx *= 2;
						v->dy *= 2;
						while (v->x0 < v->x1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->x0++;
							v->e += v->dy;
							if (v->e <= 0)
							{
								v->y0 -= 1;
								v->e += v->dx;
							}
						}
					}
					else
					{
						v->e = v->dy;
						v->dy *= 2;
						v->dx *= 2;
						while (v->y1 < v->y0)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->y0--;
							v->e += v->dx;
							if (v->e > 0)
							{
								v->x0++;
								v->e += v->dy;
							}
						}
					}
				}
			}
			else
			{
				while (v->x0 < v->x1)
				{
					mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
					v->x0++;
				}
			}
		}
		else
		{
			v->dy = v->y1 - v->y0;
			if (v->dy != 0)
			{
				if (v->dy > 0)
				{
					if (-v->dx >= v->dy)
					{
						v->e = v->dx;
						v->dx *= 2;
						v->dy *= 2;
						while (v->x0 > v->x1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->x0--;
							v->e += v->dy;
							if (v->e >= 0)
							{
								v->y0++;
								v->e += v->dx;
							}
						}
					}
					else
					{
						v->e = v->dy;
						v->dy *= 2;
						v->dx *= 2;
						while (v->y0 < v->y1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->y0++;
							v->e += v->dx;
							if (v->e <= 0)
							{
								v->x0--;
								v->e += v->dy;
							}
						}
					}
				}
				else
				{
					if (v->dx <= v->dy)
					{
						v->e = v->dx;
						v->dx *= 2;
						v->dy *= 2;
						while (v->x0 > v->x1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->x0--;
							v->e -= v->dy;
							if (v->e >= 0)
							{
								v->y0--;
								v->e += v->dx;
							}
						}
					}
					else
					{
						v->e = v->dy;
						v->dy *= 2;
						v->dx *= 2;
						while (v->y0 > v->y1)
						{
							mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
							v->y0--;
							v->e -= v->dx;
							if (v->e >= 0)
							{
								v->x0--;
								v->e += v->dy;
							}
						}
					}
				}
			}
			else
			{
				while (v->x0 > v->x1)
				{
					mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
					v->x0--;
				}
			}
		}
	}
	else
	{
		v->dy = v->y1 - v->y0;
		if (v->dy != 0)
		{
			if (v->dy > 0)
			{
				while (v->y0 < v->y1)
				{
					mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
					v->y0++;
				}
			}
			else
			{
				while (v->y0 > v->y1)
				{
					mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x0, v->y0, 0xFFFFFF);
					v->y0--;
				}
			}
		}
	}
	mlx_pixel_put(ml->mlx_ptr, ml->win_ptr, v->x1, v->y1, 0xFFFFFF);
}
