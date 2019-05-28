/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:25 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/28 17:53:36 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Initializes parameters in map struct
*/

void	ft_secure_malloc(t_mlx *m, char **nb, char **split)
{
	if (!(split = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error(2);
	if (!(m->coord = (int**)malloc((sizeof(int*) * m->nb_l) + 1)))
		ft_error(2);
	if (!(nb = (char**)malloc((sizeof(char*) * m->nb_l) + 1)))
		ft_error(2);
}

void	stock_int_tab(char *str, t_mlx *m)
{
	int		i;
	int		j;
	char	**nb;
	char	**split;

	nb = NULL;
	split = NULL;
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
			j++;
		}
		ft_strdel(&nb[j]);
		i++;
	}
	ft_free_tab((void**)split);
	ft_memdel((void**)&str);
}

/*
** Reads a m file and stores the digits in a int **tab
*/

void	read_m(int fd, t_mlx *m)
{
	int		start;
	char	*str;
	char	*line;
	int		ret;

	str = NULL;
	start = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		m->nb_l++;
		if (start == 0)
		{
			if (valid_format(line) == 1)
			{
				if (!(str = ft_strdup(line)))
					ft_error(2);
				start = 1;
			}
			else
			{
				ft_putendl("Error : not a valid map");
				exit(0);
			}
		}
		else if (!(str = ft_strjoin(str, line)))
			ft_error(2);
		if (!(str = ft_strjoin(str, "\n")))
			ft_error(2);
	}
	m->nb_w = ft_countwords(str, ' ') - 1;
	if (ret < 0)
		ft_error(2);
	if (m->nb_l == 0)
		ft_error(3);
	if ((m->nb_w / m->nb_l) < 10)
		ft_error(4);
	stock_int_tab(str, m);
}
