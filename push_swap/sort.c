/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:20:18 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/16 19:58:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_push_swap* set, float chunk)
{
	if (set->a->size == 2)
		sort_2(set);
	else if (set->a->size == 3)
		sort_3(set);
	else
		sort_over5(set, chunk);
}

void	sort_over5(t_push_swap* set, float chunk)
{
	a_to_b(set, chunk);
	b_to_a(set);
}
void	a_to_b(t_push_swap* set, float chunk)
{
	int	i;
	int value;
	int	scale;
	
	scale = set->a->size;
	i = 0;
	while (i < scale)
	{
		value = set -> a -> top -> index;
		if (value <= i)
		{
			pb(set);
			i++;
		}
		else if ((value > i) && (value <= i + chunk))
		{
			pb(set);
			rb(set);
			i++;
		}
		else if (value > chunk + i)
			ra(set);
	}
}

void	b_to_a(t_push_swap* set)
{
	int	scale;
	int	i;

	scale = set->b->size;
	i = scale - 1;
	while (i >= 0)
	{
		if (set->b->top->index == i)
		{
			pa(set);
			i--;
		}
		else
			change_top(set, i);
	}
}