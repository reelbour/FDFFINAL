/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/04 19:31:09 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* fenetre mlx */
// int x1 = 0, y1 = 0;
// int x2 = 0, y2 = 0;
// int ex = abs(x2 - x1);
// int ey = abs(y2 - y1);
// int dx = 2 * ex;
// int dy = 2 * ey;
// int Dx = ex;
// int Dy = ey;
// int i = 0;
// int X_inc = 1;
// int Y_inc = 1;
//
// if (x1 > x2)
// 	X_inc = -1;
// if (y1 > y2)
// 	Y_inc = -1;
//
// if (Dx > Dy)
// {
// 	while (i <= Dx)
// 	{
// 		put_pixels(disp, x1, y1);
// 		i++;
// 		x1 += X_inc;
// 		ex -= dy;
// 		if (ex < 0)
// 		{
// 			y1 += Y_inc;
// 			ex += dx;
// 		}
// 	}
// }
//
// if (Dx < Dy)
// {
// 	while (i <= Dx)
// 	{
// 		put_pixels(disp, x1, y1);
// 		i++;
// 		y1 += Y_inc;
// 		ey -= dx;
// 		if (ey < 0)
// 		{
// 			x1 += X_inc;
// 			ey += dy;
// 		}
// 	}
// }

int	key_press(int key, void *param)
{
	int i = 0, x = 0, y = 0;
	while (i < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y);
	}
}

void render_m()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, W, H, "test");
	mlx_key_hook(win_ptr, key_press, (void*)0);
	mlx_loop(mlx_ptr);
}
