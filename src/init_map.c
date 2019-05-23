/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/17 13:13:26 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Convert char** into int**coord **
*/

void 	ft_convert_int(t_mlx *m, char **split, char **nb)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		if (!(nb = ft_strsplit(split[i], ' ')))
			ft_error_free(2, (void**)nb);
		if (!(m->coord[i] = (int *)malloc(sizeof(int) * m->nb_w)))
			ft_error_free(2, (void**)m->coord);
		j = 0;
		while (j < (m->nb_w / m->nb_l))
		{
			m->coord[i][j] = ft_atoi(nb[j]);
			ft_strdel(&nb[j]);
			j++;
		}
		i++;
	}
}

/*
** Secure malloc for conversion **
*/

void	ft_secure_malloc(t_mlx *m, char **nb, char **split)
{
	if (!(split = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error_free(2, (void**)split);
	if (!(m->coord = (int**)malloc((sizeof(int*) * m->nb_l) + 1)))
		ft_error_free(2, (void**)m->coord);
	if (!(nb = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error_free(2, (void**)nb);
}

/*
** Stores split result into int **coord **
*/

void	stock_int_tab(char *str, t_mlx *m)
{
	char	**nb;
	char	**split;

	ft_secure_malloc(m, nb, split);
	if (!(split = ft_strsplit(str, '\n')))
		ft_error_free(2, (void**)split);
	ft_convert_int(m, split, nb);
	ft_free_tab((void**)split);
	ft_memdel((void**)&str);
}

/*
** Reads a map file and stores the digits in a int **coord **
*/

void	read_m(int fd, t_mlx *m)
{
	int		start;
	char	*str;
	char	*line;

	str = NULL;
	start = 0;
	while (get_next_line(fd, &line) > 0)
	{
		m->nb_l++;
		if (start == 0)
		{
			if (!(str = ft_strdup(line)))
				ft_error_free(2, (void**)&str);
			start = 1;
		}
		else if (!(str = ft_strjoin_free(str, line, 3)))
			ft_error_free(2, (void**)&str);
		if (!(str = ft_strjoin_free(str, "\n", 1)))
			ft_error_free(2, (void**)&str);
	}
	m->nb_w = ft_countwords(str, ' ') - 1;
	stock_int_tab(str, m);
}
