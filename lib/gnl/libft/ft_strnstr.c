/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:05:10 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/18 12:09:29 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;

	l_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len-- >= l_len)
	{
		if (*big == *little && ft_memcmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
