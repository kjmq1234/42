/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 23:37:14 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/18 19:51:55 by jaemikim         ###   ########.fr       */
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
	int	a_one;
	int	a_two;
	int	a_three;
	int	b_top;

	pb(set);
	sort_3(set);
	a_one = set->a->top->data;
	a_two = set->a->top->next->data;
	a_three = set->a->bottom->data;
	b_top = set->b->top->data;
	if (b_top < a_one)
		pa(set);
	else if ((b_top > a_one) && (b_top < a_two))
		sort_4_2(set);
	else if ((b_top > a_two) && (b_top < a_three))
		sort_4_3(set);
	else if (b_top > a_three)
		sort_4_4(set);
}

void	sort_5(t_push_swap *set)
{
	int	a_one;
	int	a_two;
	int	a_three;
	int	a_four;
	int	b_top;

	pb(set);
	sort_4(set);
	a_one = set->a->top->data;
	a_two = set->a->top->next->data;
	a_three = set->a->top->next->next->data;
	a_four = set->a->bottom->data;
	b_top = set->b->top->data;
	if (b_top < a_one)
		pa(set);
	else if ((b_top > a_one) && (b_top < a_two))
		sort_5_2(set);
	else if ((b_top > a_two) && (b_top < a_three))
		sort_5_3(set);
	else if ((b_top > a_three) && (b_top < a_four))
		sort_5_4(set);
	else if (b_top > a_four)
		sort_5_5(set);
}
