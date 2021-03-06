/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:32:23 by reelbour          #+#    #+#             */
/*   Updated: 2019/06/03 13:50:02 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Converts char **array into int **array
*/

void	convert_int_tab(t_mlx *m, char **nb, char **split, int *i)
{
	int	j;

	if (!(nb = ft_strsplit(split[*i], ' ')))
		ft_error_free(2, (void**)nb);
	if (*i == 0)
	{
		m->nb_col = 0;
		j = -1;
		while (nb[++j])
			m->nb_col++;
	}
	if (!(m->coord[*i] = (int *)ft_memalloc(sizeof(int) * m->nb_col)))
		ft_error(2);
	j = 0;
	while (j < m->nb_col && nb[j])
	{
		m->coord[*i][j] = ft_atoi(nb[j]);
		ft_strdel(&nb[j]);
		j++;
	}
	free(nb);
}

/*
** Loops and calls convert_int_tab function
*/

void	stock_int_tab(char *str, t_mlx *m)
{
	int		i;
	char	**nb;
	char	**split;

	nb = NULL;
	split = NULL;
	i = 0;
	if (!(m->coord = (int**)ft_memalloc((sizeof(int*) * m->nb_l))))
		ft_error_free(2, (void**)m->coord);
	if (!(split = ft_strsplit(str, '\n')))
		ft_error_free(2, (void**)split);
	while (split[i])
	{
		convert_int_tab(m, nb, split, &i);
		i++;
	}
	ft_free_tab_str(split);
	free(str);
}

void	stock_char_str(int *start, char **str, char **line)
{
	if (*start == 0)
	{
		if (!(*str = ft_strdup(*line)))
			ft_error(2);
		*start = 1;
		free(*line);
	}
	else if (!(*str = ft_strjoin_free(*str, *line, 3)))
		ft_error(2);
	if (!(*str = ft_strjoin_free(*str, "\n", 1)))
		ft_error(2);
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
	line = NULL;
	start = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		m->nb_l++;
		stock_char_str(&start, &str, &line);
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
