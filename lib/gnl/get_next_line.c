/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:38:21 by ahammou-          #+#    #+#             */
/*   Updated: 2018/12/19 12:59:19 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin_free(char *s1, char *s2, int d)
{
	char			*ps;
	unsigned long	len;

	if (s1 == NULL || s2 == NULL || d < 0 || d > 3)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ps = ft_strnew(len)))
		return (NULL);
	ft_strcpy(ps, s1);
	ft_strcat(ps, s2);
	if (d == 1 || d == 3)
		ft_strdel(&s1);
	if (d == 2 || d == 3)
		ft_strdel(&s2);
	return (ps);
}

int				count_endl(char **endl, const int fd)
{
	int				i;

	i = 0;
	while (endl[fd][i] && endl[fd][i] != '\n')
		i++;
	return (i);
}

int				get_line(char **endl, char **line, const int fd, int ret)
{
	char			*tmp;
	int				len;

	len = count_endl(endl, fd);
	if (endl[fd][len] == '\n')
	{
		*line = ft_strsub(endl[fd], 0, len);
		tmp = ft_strdup(endl[fd] + len + 1);
		free(endl[fd]);
		endl[fd] = tmp;
		//if (endl[fd][0] == '\0')
		//	ft_strdel(&endl[fd]);
	}
	else if (endl[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(endl[fd]);
		ft_strdel(&endl[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*endl[OPEN_MAX];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (endl[fd] == NULL)
			endl[fd] = ft_strnew(1);
		if (!(tmp = ft_strjoin_free(endl[fd], buffer, 1)))
			return (-1);
		endl[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (endl[fd] == NULL || endl[fd][0] == '\0'))
		return (0);
	return (get_line(endl, line, fd, ret));
}
