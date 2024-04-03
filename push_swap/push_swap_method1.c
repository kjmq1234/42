/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:37 by jammin            #+#    #+#             */
/*   Updated: 2024/04/03 23:11:21 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap* set)
{
    swap(set->a);
}

void	sb(t_push_swap* set)
{
    swap(set->b);
}

void	ss(t_push_swap* set)
{
    sa(set);
	sb(set);
}

void	pa(t_push_swap* set)
{
	t_element*	node;

	if (set->b->size == 0)
		return ;
	node = pop_top(set->b);
	push_top(set->a, node->data);
	free(node);
}

void	pb(t_push_swap* set)
{
	t_element*	node;

	if (set->a->size == 0)
		return ;
	node = pop_top(set->a);
	push_top(set->b, node->data);
	free(node);
}