/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:17:26 by jammin            #+#    #+#             */
/*   Updated: 2024/04/03 18:24:17 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque* deque)
{
	deque->top = NULL;
	deque->bottom = deque->top;
	deque->size = 0;
}

void	set_ab(t_deque* deque1, t_deque* deque2)
{
	t_push_swap setting;

	setting.a = deque1;
	setting.b = deque2;
}

t_element*	make_node(int data)
{
	t_element*	node;

	node = (t_element*) malloc(sizeof(t_element) * 1);
	if(!node)
		exit(1);
	node->data = data;
	node->next = NULL;
	return (node);
}