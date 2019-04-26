/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 08:39:50 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/24 11:02:33 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pmem;

	if (!(pmem = (void *)malloc(size)))
		return (NULL);
	ft_memset(pmem, 0, size);
	return (pmem);
}
