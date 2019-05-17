/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:08:43 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/15 13:33:56 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	int		n;

	n = ft_strlen(s1);
	if (!(ps1 = (char *)malloc((n + 1) * sizeof(*ps1))))
		return (NULL);
	if (ps1 == NULL)
		return (NULL);
	return (ft_strcpy(ps1, s1));
}
