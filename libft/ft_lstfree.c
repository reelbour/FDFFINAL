/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:20:22 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/31 14:24:57 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	if (!tmp)
		return ;
	while (tmp)
	{
		free(lst);
		tmp = lst;
		tmp = tmp->next;
	}
}
