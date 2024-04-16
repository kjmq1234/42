/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:53 by jammin            #+#    #+#             */
/*   Updated: 2024/04/16 15:15:21 by jaemikim         ###   ########.fr       */
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
	push_bottom(set->a, node->data, node->index);
	free(node);
	ft_putendl_fd("ra", 1);
}

void	rb(t_push_swap* set)
{
	t_element*	node;
	int			i;

	i = 1;
	if (set->b->size < 2)
		return ;
	node = pop_top(set->b);
	push_bottom(set->b, node->data, node->index);
	free(node);
	ft_putendl_fd("rb", 1);
}

void	rr(t_push_swap* set)
{
	ra(set);
	rb(set);
	ft_putendl_fd("rr", 1);
}