/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:49:13 by jammin            #+#    #+#             */
/*   Updated: 2024/04/04 20:38:27 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque* deque)
{
	t_element temp;

	if (deque->size < 2)
		return ;

	temp.data = deque->top->data;
	deque->top->data = deque->top->next->data;
	deque->top->next->data = temp.data;
}

void	push_top(t_deque* deque, int data)
{
	t_element*	node;

	node = make_node(data);
	if (deque->size == 0)
	{
		deque->top = node;
		deque->bottom = node;
	}
	else
	{
		node->next = deque->top;
		deque->top = node;
		deque->top->next->prev = deque->top;
	}
	deque->size++;
}

void	push_bottom(t_deque* deque, int data)
{
	t_element*	node;

	node = make_node(data);
	if (deque->size == 0)
	{
		deque->top = node;
		deque->bottom = node;
	}
	else
	{
		node->prev = deque->bottom;		
		deque->bottom->next = node;
		deque->bottom = node;
	}
	deque->size++;
}

t_element*	pop_top(t_deque* deque)
{
	t_element* node;

	if (deque->size == 0)
		return (NULL);
	node = deque->top;
	deque->top = node->next;
	deque->top->prev = NULL;
	node->next = NULL;
	deque->size--;
	return (node);
}

t_element*	pop_bottom(t_deque* deque)
{
	t_element* node;

	if (deque->size == 0)
		return (NULL);
	node = deque->bottom;
	deque->bottom = node->prev;
	node->prev = NULL;
	deque->bottom->next = NULL;
	deque->size--;
	return (node);
}