/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/27 18:20:09 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	valid_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] == "-" && str[i + 1] == ft_isdigit(str[i + 1])) ))
		{
			printf("%s\n", "no no no!");
		}
	}
}

void	valid_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (!ft_strstr(av, ".fdf"))
	{
		ft_putendl("Error: not a valid file");
		exit(0);
	}
}

void	ft_error_free(int nb, void **ptr)
{
	if (nb == 2)
	{
		ft_putendl("malloc failure");
		ft_free_tab_void(ptr);
		exit(0);
	}
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("can't open the file descriptor");
	if (nb == 3)
		ft_putendl("error");
	exit(0);
}
