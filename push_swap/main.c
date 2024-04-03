/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:22 by jammin            #+#    #+#             */
/*   Updated: 2024/04/03 22:58:44 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_deque deque_a;
	t_deque deque_b;
	t_push_swap push_swap;

	init_deque(&deque_a);
	init_deque(&deque_b);
	set_ab(&push_swap, &deque_a, &deque_b);
}