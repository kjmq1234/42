/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:57:14 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/16 19:17:57 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_location(t_push_swap *set, int index)
{
	t_element	*node;
	int			cnt;

	node = set->b->top;
	cnt = 0;
	while (node)
	{
		if (node->index == index)
			return (cnt);
		node = node->next;
		cnt++;
	}
	return (0);
}

void	change_top(t_push_swap* set, int i)
{
	int	move_cnt;

	move_cnt = search_location(set, i);
	if (move_cnt < i / 2)
		while (move_cnt != 0)
		{
			rb(set);
			move_cnt--;
		}
	else
		while (i >= move_cnt)
		{
			rrb(set);
			move_cnt++;
		}
}