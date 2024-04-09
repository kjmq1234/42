/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:22 by jammin            #+#    #+#             */
/*   Updated: 2024/04/10 00:22:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
int	main(int argc, char* argv[])
{
	t_deque deque_a;
	t_deque deque_b;
	t_push_swap push_swap;
	
	init_set(&push_swap, &deque_a, &deque_b);
	parse_arg_main(argc, argv, &push_swap);
	sort_main(&push_swap);
}