/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:07:35 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/24 11:06:21 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;
	size_t	ls;

	i = 0;
	ls = ft_strlen(src);
	ld = ft_strlen(dest);
	if (size <= ld)
		return (ls + size);
	while (dest[i] && i < size - 1)
		i++;
	while (*src && i < size - 1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (ld + ls);
}
