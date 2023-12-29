/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:58:28 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/12/24 02:43:09 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
