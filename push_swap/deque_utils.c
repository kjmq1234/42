/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:49:13 by jammin            #+#    #+#             */
/*   Updated: 2024/04/16 21:52:01 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_deque *deque)
{
	t_element	temp;

	if (deque->size < 2)
		return ;
	ft_swap(&deque->top->data, &deque->top->next->data);
	ft_swap(&deque->top->index, &deque->top->next->index);
}

void	push_top(t_deque *deque, int data, int index)
{
	t_element	*node;

	node = make_node(data, index);
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

void	push_bottom(t_deque *deque, int data, int index)
{
	t_element	*node;

	node = make_node(data, index);
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

t_element	*pop_top(t_deque *deque)
{
	t_element	*node;

	if (deque->size == 0)
		return (NULL);
	node = deque->top;
	if (deque->size == 1)
	{
		deque->top = NULL;
		deque->bottom = NULL;
	}
	else
	{
		deque->top = node->next;
		deque->top->prev = NULL;
		node->next = NULL;
	}
	deque->size--;
	return (node);
}

t_element	*pop_bottom(t_deque *deque)
{
	t_element	*node;

	if (deque->size == 0)
		return (NULL);
	node = deque->bottom;
	if (deque->size == 1)
	{
		deque->top = NULL;
		deque->bottom = NULL;
	}
	else
	{
		deque->bottom = node->prev;
		node->prev = NULL;
		deque->bottom->next = NULL;
	}
	deque->size--;
	return (node);
}
