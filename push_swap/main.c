/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:22 by jammin            #+#    #+#             */
/*   Updated: 2024/04/07 02:06:19 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
int	main(int argc, char* argv[])
{
	t_deque deque_a;
	t_deque deque_b;
	t_push_swap push_swap;
	
	// if (argc < 2)
	// 	error_print();
	init_set(&push_swap, &deque_a, &deque_b);
	parse_arg_main(argc, argv, &push_swap);
	// printf("top: %d, bottom: %d, size: %d\n", push_swap.a->top->data, push_swap.a->bottom->data, push_swap.a->size);
	// printf("%d", pop_top(push_swap.a)->data);
	// printf("top: %d, bottom: %d, size: %d\n", push_swap.a->top->data, push_swap.a->bottom->data, push_swap.a->size);
	// printf("%d", pop_top(push_swap.a)->data);
	// printf("size: %d\n",push_swap.a->size);
}