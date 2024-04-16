/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 23:37:14 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/16 19:26:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_push_swap *set)
{
	t_element	*one;
	t_element	*two;

	one = set->a->top;
	two = set->a->top->next;
	if (one->index > two->index)
		sa(set);
}

void	sort_3(t_push_swap *set)
{
	int	one;
	int	two;
	int	three;

	one = set->a->top->data;
	two = set->a->top->next->data;
	three = set->a->top->next->next->data;
	if ((one > two) && (two < three) && (one < three))
		sa(set);
	else if ((one > two) && (two > three) && (one > three))
	{
		sa(set);
		rra(set);
	}
	else if ((one > two) && (two < three) && (one > three))
		ra(set);
	else if ((one < two) && (two > three) && (one < three))
	{
		sa(set);
		ra(set);
	}
	else if ((one < two) && (two > three) && (one > three))
		rra(set);
}

void	sort_4(t_push_swap *set)
{
	int	a_max;
	int	a_min;
	int	b_first;
	int	a_medium;
	
	pb(set);
	sort_3(set);
	a_max = set->a->bottom->data;
	a_medium = set->a->top->next->data;
	a_min = set->a->top->data;
	b_first = set->b->top->data;
	if (a_max < b_first)
	{
		pa(set);
		ra(set);
	}
	else if (a_min > b_first)
		pa(set);
	else if ((b_first < a_max) && (b_first > a_medium))
	{
		rra(set);
		pa(set);
		ra(set);
		ra(set);
	}
}

// void	sort_5(t_push_swap *set)
// {
	
// }