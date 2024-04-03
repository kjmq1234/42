/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:40:38 by jammin            #+#    #+#             */
/*   Updated: 2024/04/03 18:23:49 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_element
{
    struct s_element*	next;
	int			data;
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


void	set_ab(t_deque* deque1, t_deque* deque2);

t_element*	make_node(int data);

#endif