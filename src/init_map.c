/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/30 20:12:58 by ahammou-         ###   ########.fr       */
=======
/*   Updated: 2019/05/08 16:10:48 by ahammou-         ###   ########.fr       */
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes all parameters in map struct
*/

void	init_m(t_m *m)
{
	m->nb_l = 0;
	m->nb_w = 0;
	m->coord = 0;
<<<<<<< HEAD
=======
	m->i = 0;
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
}

void	ft_secure_malloc(t_m *m, char **nb)
{
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
	if (!(split = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error(2);
	ft_secure_malloc(m, nb);
<<<<<<< HEAD
	if (!(split = ft_strsplit(str, '\n')))
		ft_error(2);
	while (split[i])
	{
		if (!(nb = ft_strsplit(split[i], ' ')))
			ft_error(2);
		if (!(m->coord[i] = (int *)malloc(sizeof(int) * m->nb_w)))
			ft_error(2);
=======
	split = ft_strsplit(str, '\n');
	while (split[i])
	{
		nb = ft_strsplit(split[i], ' ');
		m->coord[i] = (int *)malloc(sizeof(int) * m->nb_w);
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
		j = 0;
		while (j < (m->nb_w / m->nb_l))
		{
			m->coord[i][j] = ft_atoi(nb[j]);
<<<<<<< HEAD
			//printf("m->coord[%d][%d]: |%d|\n", i, j, m->coord[i][j]);
=======
			printf("m->coord[%d][%d]: |%d|\n", i, j, m->coord[i][j]);
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
			j++;
		}
		i++;
	}
<<<<<<< HEAD
//	ft_free_tab((void**)nb);
//	ft_free_tab((void**)split);
=======
	ft_free_tab((void**)nb);
	ft_free_tab((void**)split);
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
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
<<<<<<< HEAD
			if (!(str = ft_strdup(line)))
				ft_error(2);
			start = 1;
		}
		else
			if (!(str = ft_strjoin(str, line)))
				ft_error(2);
		if (!(str = ft_strjoin(str, "\n")))
			ft_error(2);
=======
			str = ft_strdup(line);
			start = 1;
		}
		else
			str = ft_strjoin(str, line);
		str = ft_strjoin(str, "\n");
>>>>>>> 3fe93fb0f30362086c6239896615f9be24d76407
	}
	m->nb_w = ft_countwords(str, ' ') - 1;
	stock_int_tab(str, m);
}
