/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:22 by jammin            #+#    #+#             */
/*   Updated: 2024/05/19 16:15:12 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque		deque_a;
	t_deque		deque_b;
	t_push_swap	push_swap;
	float		chunk;
	int			count;

	init_set(&push_swap, &deque_a, &deque_b);
	count = parse_arg_main(argc, argv, &push_swap);
	chunk = (count * count * 0.000000053) + (count * 0.03) + 14.5;
	sort_main(&push_swap, chunk);
	free_stack(push_swap.a);
	free_stack(push_swap.b);
}
