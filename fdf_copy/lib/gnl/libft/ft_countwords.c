/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:01:53 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/31 13:02:00 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}
