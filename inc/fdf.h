/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:50:09 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/27 17:52:52 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define W 1560
# define H 1300
# define Z_MIN 0.40
# define Z_MAX 3
# define A_MIN -5
# define A_MAX 5
# define Q_KEY 12
# define A_KEY 0
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define PLUS_KEY 69
# define MINUS_KEY 78

# include <stdio.h>

typedef struct	s_dot
{
	int		x;
	int		y;
}				t_dot;

/*
** GLOBAL STRUCTURE **
*/

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		nb_l;
	int		nb_w;
	float	z;
	int		sx;
	int		sy;
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		clr;
	int		check;
	float	zoom;
	int		**coord;
	int		p;
}				t_mlx;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			read_m(int fd, t_mlx *m);
int				count_words(char *str);
void			stock_int_tab(char *str, t_mlx *m);
void			convert_int(t_mlx *m, char **split);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int nb);
void			ft_error_free(int nb, void **ptr);
void			valid_extension(char *av);
void			valid_format(char *str);
/*
** ==================== FUNCTIONS IN RENDER.C ==================== **
*/

void			render_m(t_mlx *m);
void			draw(t_mlx *m);
void			draw_lines(t_mlx *m, int x, int y);
void			choose_projection(t_mlx *m, int x, int y);
/*
** ==================== FUNCTIONS IN DRAW.C ==================== **
*/

void			draw_line(t_mlx *m, t_dot tabxy, int x, int y);
t_dot			rasterize_para(t_mlx *m, int x, int y, int z);
t_dot			rasterize_iso(t_mlx *m, int x, int y, int z);
void			draw_m_para(t_mlx *m, int x, int y);
void			draw_m_iso(t_mlx *m, int x, int y);

/*
** ==================== FUNCTIONS IN KEYMAP.C ==================== **
*/

int				deal_key(int key, void *param);
int				deal_mouse(int scroll, void *param);
void			draw_string(t_mlx *m);
char			*ft_strjoin_free(char *s1, char *s2, int d);
#endif
