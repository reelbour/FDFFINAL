/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:00:45 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/15 11:58:07 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	else
	{
		while (n--)
		{
			if (*ps1 != *ps2)
				return (*ps1 - *ps2);
			if (n)
			{
				ps1++;
				ps2++;
			}
		}
	}
	return (*ps1 - *ps2);
}
