/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:40:38 by jammin            #+#    #+#             */
/*   Updated: 2024/04/09 21:48:39 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_element
{
    struct s_element*	next;
    struct s_element*	prev;
	int					data;
	int					index;
} t_element;

typedef struct s_deque
{
	struct s_element*	top;
	struct s_element*	bottom;
	int size;
} t_deque;

typedef struct s_push_swap
{
	t_deque*	a;
	t_deque*	b;
} t_push_swap;



void	init_deque(t_deque* deque);
void	swap(t_deque* deque);
void	push_bottom(t_deque* deque, int data);
void	push_top(t_deque* deque, int data);
t_element*	pop_top(t_deque* deque);
t_element*	pop_bottom(t_deque* deque);
void	init_set(t_push_swap* set, t_deque* deque1, t_deque* deque2);
void	error_print(void);


void	sa(t_push_swap* set);
void	sb(t_push_swap* set);
void	ss(t_push_swap* set);
void	pa(t_push_swap* set);
void	pb(t_push_swap* set);
void	ra(t_push_swap* set);
void	rb(t_push_swap* set);
void	rr(t_push_swap* set);
void    rra(t_push_swap* set);
void    rrb(t_push_swap* set);
void    rrr(t_push_swap* set);

t_element*	make_node(int data);

int		count_args(int argc, char** argv);
void	parse_arg_main(int argc, char** argv, t_push_swap* set);
void	parsing_arg(int argc, char** argv, int* array);
void	arg_into_stack(t_push_swap* set, int* array, int scale);
void	ft_swap(int* a, int* b);
void	exit_sorted_numbers(int* array);
void	duplicate_check(int *array, int count);
void	add_index(int* array, t_deque* deque);

#endif