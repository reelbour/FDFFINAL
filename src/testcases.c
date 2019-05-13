/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:21:14 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/13 12:54:34 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	testcases(t_v *v, t_ml *ml)
{
	//********** bottom right
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 200;
	v->y1 = 200;
	draw_line(v, ml);
	//********** top left
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 0;
	v->y1 = 0;
	draw_line(v, ml);
	//********** top right
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 200;
	v->y1 = 0;
	draw_line(v, ml);
	//********** bottom left
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 0;
	v->y1 = 200;
	draw_line(v, ml);
	//********** center right
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 200;
	v->y1 = 100;
	draw_line(v, ml);
	//********** center left
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 0;
	v->y1 = 100;
	draw_line(v, ml);
	//********** center up
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 100;
	v->y1 = 0;
	draw_line(v, ml);
	//********** center up
	v->x0 = 100;
	v->y0 = 100;
	v->x1 = 100;
	v->y1 = 200;
	draw_line(v, ml);
	//********** border bottom right
	v->x0 = 200;
	v->y0 = 100;
	v->x1 = 200;
	v->y1 = 200;
	draw_line(v, ml);
	//********** border
	v->x0 = 200;
	v->y0 = 100;
	v->x1 = 200;
	v->y1 = 0;
	draw_line(v, ml);
}
