/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:50:09 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/20 11:19:01 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define W 1560
# define H 1300
# include <stdio.h>

/*
** STRUCTURE IMAGES **
*/

typedef struct	s_i
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_i;

/*
** GLOBAL STRUCTURE **
*/

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_i		*img;
	int		nb_l;
	int		nb_w;
	int		z;
	int		sx;
	int		sy;
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		clr;
	int		check;
	int		**coord;
}				t_mlx;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			read_m(int fd, t_mlx *m);
int				count_words(char *str);
void			stock_int_tab(char *str, t_mlx *m);
void			ft_secure_malloc(t_mlx *m, char **nb, char **split);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int n);

/*
** ==================== FUNCTIONS IN RENDER.C ==================== **
*/

void			render_m(t_mlx *m);
void			draw(t_mlx *m);
void			draw_lines(t_mlx *m, int x, int y);
void			draw_line(t_mlx *m, int *tabxy, int x, int y);

/*
** ==================== FUNCTIONS IN KEYMAP.C ==================== **
*/

int				deal_key(int key, void *param);
int				deal_mouse(int scroll, void *param);
#endif
