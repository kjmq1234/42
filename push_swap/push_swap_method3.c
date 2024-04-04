/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:24:31 by jammin            #+#    #+#             */
/*   Updated: 2024/04/04 19:34:31 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_push_swap* set)
{
    t_element*	node;
	int			i;

	i = 1;
	if (set->a->size < 2)
		return ;
	node = pop_bottom(set->a);
	push_top(set->a, node->data);
	free(node);
}

void    rrb(t_push_swap* set)
{
    t_element*	node;
	int			i;

	i = 1;
	if (set->b->size < 2)
		return ;
	node = pop_bottom(set->b);
	push_top(set->b, node->data);
	free(node);
}

void rrr(t_push_swap* set)
{
    rra(set);
    rrb(set);
}