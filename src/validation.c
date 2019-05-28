/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:57:55 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/28 17:52:31 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		valid_format(char *str)
{
	int	i;
	int res;

	i = 0;
	res = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-' || (str[i] > 47 && str[i] < 58))
			i++;
		else
		{
			res = 0;
			break ;
		}
	}
	return (res);
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
		ft_putendl("Error : malloc failure");
		ft_free_tab_void(ptr);
		exit(0);
	}
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("Error : can't open the file descriptor");
	if (nb == 2)
		ft_putendl("Error : can't read the file descriptor");
	if (nb == 3)
		ft_putendl("Error");
	if (nb == 4)
		ft_putendl("Error: need at least 10 digits per line");
	exit(0);
}
