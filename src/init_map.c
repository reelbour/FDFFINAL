/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:32:23 by reelbour          #+#    #+#             */
/*   Updated: 2019/06/02 14:09:52 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
** Initializes parameters in map struct
*/

void	ft_secure_malloc(t_mlx *m, char **nb, char **split)
{
	if (!(split = (char**)malloc((sizeof(char*) * (m->nb_l + 1)))))
		ft_error(2);
	if (!(m->coord = (int**)ft_memalloc((sizeof(int*) * (m->nb_l + 1)))))
		ft_error(2);
	if (!(nb = (char**)malloc((sizeof(char*) * (m->nb_l + 1)))))
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
		if (i == 0)
		{
			m->nb_col = 0;
			j = -1;
			while (nb[++j])
				m->nb_col++;
		}
		if (!(m->coord[i] = (int *)ft_memalloc(sizeof(int) * m->nb_col)))
			ft_error(2);
		j = 0;
		while (j < m->nb_col && nb[j])
		{
			m->coord[i][j] = ft_atoi(nb[j]);
			// printf("%d ", m->coord[i][j]);
			j++;
		}
		// printf("\n");
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
	int		check_w;

	check_w = 0;
	str = NULL;
	line = NULL;
	start = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		m->nb_l++;
		check_w = ft_countwords(line, ' ') - 1;
		if (start == 0)
		{
			if (!(str = ft_strdup(line)))
				ft_error(2);
			start = 1;
			free(line);
		}
		else if (!(str = ft_strjoin_free(str, line, 3)))
			ft_error(2);
		if (!(str = ft_strjoin_free(str, "\n", 1)))
			ft_error(2);
		if (m->nb_l > 502)
			ft_error(4);
	}
	m->nb_w = ft_countwords(str, ' ') - 1;
	if (ret < 0)
		ft_error(2);
	if (m->nb_l == 0)
		ft_error(3);
	stock_int_tab(str, m);
	if (m->nb_col < 2)
		ft_error(4);
}
