/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:51:28 by ahammou-          #+#    #+#             */
/*   Updated: 2019/05/17 12:51:31 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstdestroy(t_list **lst)
{
	t_list *save;

	while (*lst)
	{
		save = *lst;
		*lst = (*lst)->next;
		ft_memdel(&(save->content));
		ft_memdel((void **)&save);
	}
	*lst = NULL;
	return (0);
}
