/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:24:31 by jammin            #+#    #+#             */
/*   Updated: 2024/04/16 22:01:24 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *set)
{
	t_element	*node;
	int			i;

	i = 1;
	if (set->a->size < 2)
		return ;
	node = pop_bottom(set->a);
	push_top(set->a, node->data, node->index);
	free(node);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_push_swap *set)
{
	t_element	*node;
	int			i;

	i = 1;
	if (set->b->size < 2)
		return ;
	node = pop_bottom(set->b);
	push_top(set->b, node->data, node->index);
	free(node);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_push_swap *set)
{
	rra(set);
	rrb(set);
	ft_putendl_fd("rrr", 1);
}
