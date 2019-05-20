/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:41:14 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/24 11:10:59 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ps;
	int		i;
	int		len;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(ps = ft_strnew(len)))
		return (NULL);
	while (s[i])
	{
		ps[i] = f(s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
