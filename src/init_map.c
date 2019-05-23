/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/23 16:48:38 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Convert char** into int**coord **
*/

void	ft_convert_int(t_mlx *m, char **split)
{
	int		i;
	int		j;
	char	**nb;

	nb = NULL;
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
			j++;
		}
		ft_free_tab_str(nb);
		i++;
	}
	ft_free_tab_str(split);
}

/*
** Stores split result into int **coord **
*/

void	stock_int_tab(char **str, t_mlx *m)
{
	char	**split;

	if (!(m->coord = (int**)malloc((sizeof(int*) * m->nb_l) + 1)))
		ft_error_free(2, (void**)m->coord);
	if (!(split = ft_strsplit(*str, '\n')))
		ft_error_free(2, (void**)split);
	ft_convert_int(m, split);
}

/*
** Reads a map file and stores the digits in a int **coord **
*/

void	read_m(int fd, t_mlx *m)
{
	int		start;
	char	*str;
	char	*line;

	line = NULL;
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
			free(line);
		}
		else if (!(str = ft_strjoin_free(str, line, 3)))
			ft_error_free(2, (void**)&str);
		if (!(str = ft_strjoin_free(str, "\n", 1)))
			ft_error_free(2, (void**)&str);
	}
	m->nb_w = ft_countwords(str, ' ') - 1;
	stock_int_tab(&str, m);
	free(str);
}
