/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:06:37 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/18 12:07:13 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dst, const char *src)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(src);
	i = 0;
	j = 0;
	if (len == 0)
		return ((char *)dst);
	while (dst[i])
	{
		while (src[j] == dst[i + j])
		{
			if (j == len - 1)
				return ((char *)dst + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
