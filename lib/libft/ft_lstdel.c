/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:30:13 by ahammou-          #+#    #+#             */
/*   Updated: 2018/10/31 13:05:01 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*list_next;

	if (!alst || !*alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		list_next = list->next;
		del(list->content, list->content_size);
		free(list);
		list = list_next;
	}
	*alst = NULL;
}
