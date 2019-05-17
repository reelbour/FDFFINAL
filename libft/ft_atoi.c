/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 08:36:29 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/30 12:27:42 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int						sign;
	char					*cur;
	unsigned long long		result;

	result = 0;
	cur = (char *)str;
	while (ft_isspace(*cur))
		cur++;
	sign = (*cur == '-') ? -1 : 1;
	cur = (*cur == '+' || *cur == '-') ? cur + 1 : cur;
	while (*cur >= '0' && *cur <= '9')
	{
		result = result * 10 + *cur - 48;
		cur++;
	}
	if (result > (long int)9223372036854775807)
		return ((sign == -1) ? 0 : -1);
	result *= sign;
	return (result);
}
