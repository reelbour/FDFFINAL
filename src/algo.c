/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:25:52 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/17 12:45:26 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/fdf.h"

 void	draw_line(t_mlx *m, int *t_xy, int x, int y)
 {
 	m->dx = m->x1 - m->x0;
 	if (m->dx != 0)
 	{
 		if (m->dx > 0)
 		{
 			m->dy = m->y1 - m->y0;
 			if (m->dy != 0)
 			{
 				if (m->dy > 0)
 				{
 					if (m->dx >= m->dy)
 					{
 						m->e = m->dx;
 						m->dx = m->e * 2;
 						m->dy = m->dy * 2;
 						while (m->x0 < m->x1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->x0++;
 							m->e -= m->dy;
 							if (m->e <= 0)
 							{
 								m->y0++;
 								m->e += m->dx;
 							}
 						}
 					}
 					else
 					{
 						m->e = m->dy;
 						m->dy = m->e * 2;
 						m->dx = m->dx * 2;
 						while (m->y0 < m->y1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->y0++;
 							m->e -= m->dx;
 							if (m->e <= 0)
 							{
 								m->x0++;
 								m->e += m->dy;
 							}
 						}
 					}
 				}
 				else
 				{
 					if (m->dx >= -m->dy)
 					{
 						m->e = m->dx;
 						m->dx *= 2;
 						m->dy *= 2;
 						while (m->x0 < m->x1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->x0++;
 							m->e += m->dy;
 							if (m->e <= 0)
 							{
 								m->y0 -= 1;
 								m->e += m->dx;
 							}
 						}
 					}
 					else
 					{
 						m->e = m->dy;
 						m->dy *= 2;
 						m->dx *= 2;
 						while (m->y1 < m->y0)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->y0--;
 							m->e += m->dx;
 							if (m->e > 0)
 							{
 								m->x0++;
 								m->e += m->dy;
 							}
 						}
 					}
 				}
 			}
 			else
 			{
 				while (m->x0 < m->x1)
 				{
 					mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 					m->x0++;
 				}
 			}
 		}
 		else
 		{
 			m->dy = m->y1 - m->y0;
 			if (m->dy != 0)
 			{
 				if (m->dy > 0)
 				{
 					if (-m->dx >= m->dy)
 					{
 						m->e = m->dx;
 						m->dx *= 2;
 						m->dy *= 2;
 						while (m->x0 > m->x1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->x0--;
 							m->e += m->dy;
 							if (m->e >= 0)
 							{
 								m->y0++;
 								m->e += m->dx;
 							}
 						}
 					}
 					else
 					{
 						m->e = m->dy;
 						m->dy *= 2;
 						m->dx *= 2;
 						while (m->y0 < m->y1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->y0++;
 							m->e += m->dx;
 							if (m->e <= 0)
 							{
 								m->x0--;
 								m->e += m->dy;
 							}
 						}
 					}
 				}
 				else
 				{
 					if (m->dx <= m->dy)
 					{
 						m->e = m->dx;
 						m->dx *= 2;
 						m->dy *= 2;
 						while (m->x0 > m->x1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->x0--;
 							m->e -= m->dy;
 							if (m->e >= 0)
 							{
 								m->y0--;
 								m->e += m->dx;
 							}
 						}
 					}
 					else
 					{
 						m->e = m->dy;
 						m->dy *= 2;
 						m->dx *= 2;
 						while (m->y0 > m->y1)
 						{
 							mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 							m->y0--;
 							m->e -= m->dx;
 							if (m->e >= 0)
 							{
 								m->x0--;
 								m->e += m->dy;
 							}
 						}
 					}
 				}
 			}
 			else
 			{
 				while (m->x0 > m->x1)
 				{
 					mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 					m->x0--;
 				}
 			}
 		}
 	}
 	else
 	{
 		m->dy = m->y1 - m->y0;
 		if (m->dy != 0)
 		{
 			if (m->dy > 0)
 			{
 				while (m->y0 < m->y1)
 				{
 					mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 					m->y0++;
 				}
 			}
 			else
 			{
 				while (m->y0 > m->y1)
 				{
 					mlx_pixel_put(m->mlx, m->win, m->x0, m->y0, 0xFFFFFF);
 					m->y0--;
 				}
 			}
 		}
 	}
 	mlx_pixel_put(m->mlx, m->win, m->x1, m->y1, 0xFFFFFF);
 }
