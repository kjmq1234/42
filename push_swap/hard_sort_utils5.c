/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:39:59 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/18 19:18:52 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_2(t_push_swap *set)
{
	pa(set);
	sa(set);
}

void	sort_5_3(t_push_swap *set)
{
	rra(set);
	rra(set);
	pa(set);
	rra(set);
	rra(set);
}

void	sort_5_4(t_push_swap *set)
{
	rra(set);
	pa(set);
	ra(set);
	ra(set);
}

void	sort_5_5(t_push_swap *set)
{
	pa(set);
	ra(set);
}
