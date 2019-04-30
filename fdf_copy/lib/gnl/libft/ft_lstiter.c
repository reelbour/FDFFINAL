/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:25:37 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/30 12:32:41 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*list_next;

	if (!lst || !f)
		return ;
	while (lst)
	{
		list_next = lst->next;
		f(lst);
		lst = list_next;
	}
}
