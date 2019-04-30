/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/30 19:23:08 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes all parameters in map struct
*/

void	init_m(t_m *m)
{
	m->line = NULL;
	m->str = NULL;
	m->nb_l = 0;
	m->nb_w = 0;
	m->coord = 0;
}

void	ft_secure_malloc(t_m *m, char **nb)
{
	if (!(m->split = (char**)malloc((sizeof(char) * m->nb_w) * m->nb_l)))
		ft_error(2);
	if (!(m->coord = (int**)malloc(sizeof(int *) * m->nb_l + 1)))
		ft_error(2);
	if (!(nb = (char**)malloc((sizeof(char) * m->nb_w) * m->nb_l)))
		ft_error(2);
}

void	stock_int_tab(t_m *m)
{
	int		i;
	int		j;
	char	**nb;

	i = 0;
	ft_secure_malloc(m, nb);
	m->split = ft_strsplit(m->str, '\n');
	while (m->split[i])
	{
		nb = ft_strsplit(m->split[i], ' ');
		m->coord[i] = (int *)malloc(sizeof(m->nb_w / m->nb_l));
		j = 0;
		while (j < (m->nb_w / m->nb_l))
		{
			m->coord[i][j] = ft_atoi(nb[j]);
			printf("m->coord[%d][%d]: |%d|\n", i, j, m->coord[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_free_tab((void**)nb);
}

/*
** Reads a m file and stores the digits in a int **tab
*/

void	read_m(int fd, t_m *m)
{
	int	start;

	start = 0;
	while (get_next_line(fd, &m->line) > 0)
	{
		m->nb_l++;
		if (start == 0)
		{
			m->str = ft_strdup(m->line);
			start = 1;
		}
		else
			m->str = ft_strjoin(m->str, m->line);
		m->str = ft_strjoin(m->str, "\n");
	}
	m->nb_w = ft_countwords(m->str, ' ') - 1;
	stock_int_tab(m);
}
