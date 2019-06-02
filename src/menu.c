/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:08:41 by ahammou-          #+#    #+#             */
/*   Updated: 2019/06/02 16:24:29 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_string(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 5, 10, 0xFFFFFF, "WELCOME ON THIS FDF");
	mlx_string_put(m->mlx, m->win, 5, 35, 0xFFFFFF, "By Ahammou- and Reelbour");
	mlx_string_put(m->mlx, m->win, 5, 60, 0xFFFFFF, "COMMANDS:");
	mlx_string_put(m->mlx, m->win, 5, 85, 0xFFFFFF, "=======================");
	mlx_string_put(m->mlx, m->win, 5, 110, 0xFFFFFF, "Move : arrows < ^ >");
	mlx_string_put(m->mlx, m->win, 5, 135, 0xFFFFFF,
		"Altitude : q(up),a(down)");
	mlx_string_put(m->mlx, m->win, 5, 160, 0xFFFFFF, "Zoom : + and -");
	mlx_string_put(m->mlx, m->win, 5, 185, 0xFFFFFF, "Switch view : 1 or 2");
	mlx_string_put(m->mlx, m->win, 5, 210, 0xFFFFFF, "Reset map : r");
}
