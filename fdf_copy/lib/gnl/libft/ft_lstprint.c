/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:05:14 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/31 13:29:33 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	while (list)
	{
		ft_putstr((char *)(list->content));
		ft_putchar('\n');
		list = list->next;
	}
}
