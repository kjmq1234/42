/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:30:43 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/16 21:21:10 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(int* array, t_push_swap* set)
{
	int			i;
	t_element*	que;

	i = 0;
	while (i < set->a->size)
	{
		que = set->a->top;
		while (que->next)
		{
			if (que->data == array[i])
			{
				que->index = i;
				break;
			}
			que = que->next;
		}
		if (que->data == array[i])
			que->index = i;
		i++;
	}
}