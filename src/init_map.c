/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/12 16:40:47 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes parameters in map struct
*/

void	init_m(t_m *m)
{
	m->nb_l = 0;
	m->nb_w = 0;
	m->coord = 0;
	m->x = 0;
	m->y = 0;
}

void	ft_secure_malloc(t_m *m, char **nb, char **split)
{
	if (!(split = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error(2);
	if (!(m->coord = (int**)malloc(sizeof(int*) * m->nb_l + 1)))
		ft_error(2);
	if (!(nb = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error(2);
}

void	stock_int_tab(char *str, t_m *m)
{
	int		i;
	int		j;
	char	**nb;
	char	**split;

	i = 0;
	ft_secure_malloc(m, nb, split);
	split = ft_strsplit(str, '\n');
	while (split[i])
	{
		nb = ft_strsplit(split[i], ' ');
		if (!(m->coord[i] = (int *)malloc(sizeof(int) * m->nb_w)))
			ft_error(2);
		j = 0;
		while (j < (m->nb_w / m->nb_l))
		{
			m->coord[i][j] = ft_atoi(nb[j]);
			//printf("m->coord[%d][%d]: |%d|\n", i, j, m->coord[i][j]);
			j++;
		}
		i++;
	}
	ft_free_tab((void**)nb);
	ft_free_tab((void**)split);
	ft_memdel((void**)&str);
}

/*
** Reads a m file and stores the digits in a int **tab
*/

void	read_m(int fd, t_m *m)
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
				ft_error(2);
			start = 1;
		}
		else if (!(str = ft_strjoin(str, line)))
				ft_error(2);
		if (!(str = ft_strjoin(str, "\n")))
			ft_error(2);
	}
	m->nb_w = ft_countwords(str, ' ');
	stock_int_tab(str, m);
}
