/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:58:28 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/11/02 23:58:49 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*nextptr;

	if ((!lst) || (!del))
		return ;
	if (!*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		nextptr = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = nextptr;
	}
	*lst = NULL;
}
