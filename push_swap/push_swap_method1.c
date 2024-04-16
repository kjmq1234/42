/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:37 by jammin            #+#    #+#             */
/*   Updated: 2024/04/16 15:21:33 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap* set)
{
    stack_swap(set->a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_push_swap* set)
{
    stack_swap(set->b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_push_swap* set)
{
    sa(set);
	sb(set);
	ft_putendl_fd("ss", 1);
}

void	pa(t_push_swap* set)
{
	t_element*	node;

	if (set->b->size == 0)
		return ;
	node = pop_top(set->b);
	push_top(set->a, node->data, node->index);
	free(node);
	ft_putendl_fd("pa", 1);
}

void	pb(t_push_swap* set)
{
	t_element*	node;

	if (set->a->size == 0)
		return ;
	node = pop_top(set->a);
	push_top(set->b, node->data, node->index);
	free(node);
	ft_putendl_fd("pb", 1);
}