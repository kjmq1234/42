/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:49:13 by jammin            #+#    #+#             */
/*   Updated: 2024/04/03 18:24:21 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque* deque)
{
	t_element temp;

	if (deque->size < 2)
		return ;

	temp.data = deque->top->data;
	deque->top->data = deque->bottom->data;
	deque->bottom->data = temp.data;
}

void	push_top(t_deque* deque, int data)
{
	t_element*	node;

	node = make_node(data);
	if (deque->size == 0)
		deque->bottom = node;
	node->next = deque->top;
	deque->top = node;
	deque->size++;
}