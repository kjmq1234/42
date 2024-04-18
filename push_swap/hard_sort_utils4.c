/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:39:59 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/18 18:59:18 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_2(t_push_swap *set)
{
	pa(set);
	sa(set);
}

void	sort_4_3(t_push_swap *set)
{
	rra(set);
	pa(set);
	ra(set);
	ra(set);
}

void	sort_4_4(t_push_swap *set)
{
	pa(set);
	ra(set);
}