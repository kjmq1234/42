/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:17:26 by jammin            #+#    #+#             */
/*   Updated: 2024/04/16 21:52:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *deque)
{
	deque->top = NULL;
	deque->bottom = NULL;
	deque->size = 0;
}

void	init_set(t_push_swap *set, t_deque *deque1, t_deque *deque2)
{
	init_deque(deque1);
	init_deque(deque2);
	set->a = deque1;
	set->b = deque2;
}

t_element	*make_node(int data1, int index1)
{
	t_element	*node;

	node = (t_element *) malloc(sizeof(t_element) * 1);
	if (!node)
		exit(1);
	node->data = data1;
	node->index = index1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
