/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:17:26 by jammin            #+#    #+#             */
/*   Updated: 2024/04/04 20:41:05 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque* deque)
{
	deque->top = NULL;
	deque->bottom = NULL;
	deque->size = 0;
}

void	init_set(t_push_swap* set, t_deque* deque1, t_deque* deque2)
{
	set->a = deque1;
	set->b = deque2;
}

t_element*	make_node(int data1)
{
	t_element*	node;

	node = (t_element*) malloc(sizeof(t_element) * 1);
	if(!node)
		exit(1);
	node->data = data1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}