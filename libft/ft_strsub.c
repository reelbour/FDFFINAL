/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:31:31 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/23 12:11:32 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ps;

	if (s == NULL)
		return (NULL);
	if (!(ps = ft_strnew(len)))
		return (NULL);
	ft_strncpy(ps, s + start, len);
	ps[len] = '\0';
	return (ps);
}
