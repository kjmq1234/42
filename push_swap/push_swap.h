/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:40:38 by jammin            #+#    #+#             */
/*   Updated: 2024/04/18 19:06:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_element
{
	struct s_element	*next;
	struct s_element	*prev;
	int					data;
	int					index;
}	t_element;

typedef struct s_deque
{
	struct s_element	*top;
	struct s_element	*bottom;
	int					size;
}	t_deque;

typedef struct s_push_swap
{
	t_deque	*a;
	t_deque	*b;
}	t_push_swap;

void		init_deque(t_deque *deque);
void		stack_swap(t_deque *deque);
void		push_bottom(t_deque *deque, int data, int index);
void		push_top(t_deque *deque, int data, int index);
t_element	*pop_top(t_deque *deque);
t_element	*pop_bottom(t_deque *deque);
void		init_set(t_push_swap *set, t_deque *deque1, t_deque *deque2);
void		error_print(void);
void		sa(t_push_swap *set);
void		sb(t_push_swap *set);
void		ss(t_push_swap *set);
void		pa(t_push_swap *set);
void		pb(t_push_swap *set);
void		ra(t_push_swap *set);
void		rb(t_push_swap *set);
void		rr(t_push_swap *set);
void		rra(t_push_swap *set);
void		rrb(t_push_swap *set);
void		rrr(t_push_swap *set);
t_element	*make_node(int data1, int index1);
void		free_stack(t_deque *stack);
int			count_args(int argc, char **argv);
int			parse_arg_main(int argc, char **argv, t_push_swap *set);
void		parsing_arg(int argc, char **argv, int *array);
void		arg_into_stack(t_push_swap *set, int *array, int scale);
void		ft_swap(int *a, int *b);
void		exit_sorted_numbers(int *array, t_push_swap *set);
void		duplicate_check(int *array, int count, t_push_swap *set);
void		add_index(int *array, t_push_swap *set);
void		sort_2(t_push_swap *set);
void		sort_3(t_push_swap *set);
void		sort_over5(t_push_swap *set, float chunk);
void		sort_main(t_push_swap *set, float chunk);
void		a_to_b(t_push_swap *set, float chunk);
void		b_to_a(t_push_swap *set);
int			wordcnt(char const *s, char c);
int			search_location(t_push_swap *set, int index);
void		change_top(t_push_swap *set, int i);
void		sort_4(t_push_swap *set);
void		sort_4_2(t_push_swap *set);
void		sort_4_3(t_push_swap *set);
void		sort_4_4(t_push_swap *set);
void		sort_5(t_push_swap *set);
void		sort_5_2(t_push_swap *set);
void		sort_5_3(t_push_swap *set);
void		sort_5_4(t_push_swap *set);
void		sort_5_5(t_push_swap *set);

#endif