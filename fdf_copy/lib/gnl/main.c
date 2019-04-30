/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:46:21 by ahammou-          #+#    #+#             */
/*   Updated: 2019/04/25 16:18:19 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	if (ac < 2)
	{
		ft_putendl("no entry");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	 while (get_next_line(fd, &line) == 1)
	 {
		 printf("%s\n", line);
		 ft_strdel(&line);
	 }
	 close(fd);

	/*while (1)
	{
		fd = open("Users/ahammou-/gnl/get_next_line.c", O_RDONLY);
		while ((ret = get_next_line(fd, &line)) == 1)
			printf("line: %s\n", line);
		close(fd);
	}*/
	
	return (0);
}
