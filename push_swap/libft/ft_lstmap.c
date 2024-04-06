/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:50:36 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/12/24 02:43:34 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*edit;

	newlst = NULL;
	if ((!lst) || (!f) || (!del))
		return (0);
	while (lst)
	{
		edit = f(lst->content);
		new = ft_lstnew(edit);
		if (!new)
		{
			del(edit);
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
