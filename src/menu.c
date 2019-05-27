/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:08:41 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/27 17:09:44 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_string(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 5, 10, 0xFFFFFF, "WELCOME ON THIS FDF");
	mlx_string_put(m->mlx, m->win, 5, 35, 0xFFFFFF, "By Ahammou- and Reelbour");
	mlx_string_put(m->mlx, m->win, 5, 100, 0xFFFFFF, "COMMANDS:");
	mlx_string_put(m->mlx, m->win, 5, 115, 0xFFFFFF, "=======================");
	mlx_string_put(m->mlx, m->win, 5, 140, 0xFFFFFF, "Move : arrows < ^ >");
	mlx_string_put(m->mlx, m->win, 5, 165, 0xFFFFFF,
		"Altitude : q(up),a(down)");
	mlx_string_put(m->mlx, m->win, 5, 190, 0xFFFFFF, "Zoom : + and -");
	mlx_string_put(m->mlx, m->win, 5, 215, 0xFFFFFF, "Switch view : 1 or 2");
}
