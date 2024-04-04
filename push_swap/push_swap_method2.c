/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:53 by jammin            #+#    #+#             */
/*   Updated: 2024/04/04 19:32:14 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap* set)
{
	t_element*	node;
	int			i;

	i = 1;
	if (set->a->size < 2)
		return ;
	node = pop_top(set->a);
	push_bottom(set->a, node->data);
	free(node);
}

void	rb(t_push_swap* set)
{
	t_element*	node;
	int			i;

	i = 1;
	if (set->b->size < 2)
		return ;
	node = pop_top(set->b);
	push_bottom(set->b, node->data);
	free(node);
}

void	rr(t_push_swap* set)
{
	ra(set);
	rb(set);
}