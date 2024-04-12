/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:20:18 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/13 04:49:08 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_push_swap* set, int chunk)
{
	if (set->a->size == 2)
		sort_2(set);
	else if (set->a->size == 3)
		sort_3(set);
	else
		sort_over5(set, chunk);
}

void	sort_over5(t_push_swap* set, int chunk)
{
	a_to_b(set, chunk);
	b_to_a(set);
}
void	a_to_b(t_push_swap* set, int chunk)
{
	int	i;

	i = 0;
	while (set->a->size != 0)
	{
		if (set->a->top->index <= i)
		{
			pb(set);
			i++;
		}
			else if ((set->a->top->index > i) && (set->a->top->index <= i + chunk))
		{
			pb(set);
			rb(set);
			i++;
		}
		else 
		{
			if (i < set->a->size / 2)
				rra(set);
			else
				ra(set);
		}
	}
}

void	b_to_a(t_push_swap* set)
{
	while (set->b->size != 0)
	{
		if (set->b->top->index < set->b->bottom->index)
			rrb(set);
		pa(set);
	}
}