/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:30:43 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/10 12:24:56 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(int* array, t_deque* deque)
{
	int			i;
	t_element*	que;

	i = 0;
	while (array[i])
	{
		que = deque->top;
		while (que)
		{
			if (que->data == array[i])
			{
				que->index = i;
				break;
			}
			que = que->next;
		}
		i++;
	}
	// 	t_element* a;
	// 	a = deque->top;
	// while (a)
	// {
	// 	printf("data: %d index: %d\n", a->data, a->index);
	// 	a = a->next;
	// }
}