/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:52:42 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/15 10:31:35 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *pd;
	char *ps;

	pd = (char*)dst;
	ps = (char*)src;
	if (len == 0 || pd == ps)
		return (dst);
	if (pd < ps)
		ft_memcpy(pd, ps, len);
	else
	{
		pd += len;
		ps += len;
		while (len--)
			*--pd = *--ps;
	}
	return (dst);
}
