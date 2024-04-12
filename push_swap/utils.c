/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:12:13 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/13 04:53:32 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	ft_putendl_fd("Error", 1);
	// exit(1);
}

void	ft_swap(int* a, int* b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b =tmp;
}

void	exit_sorted_numbers(int* array)
{
	free(array);
	exit(0);
}

void	free_stack(t_deque* stack)
{
	t_element* tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
		tmp->prev = NULL;
	}
	free(tmp);
}

int	wordcnt(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	if (!s)
		exit(1);
	while (*s)
	{
		while ((*s == c) && (*s))
			s++;
		if ((*s != c) && (*s))
			cnt++;
		while ((*s != c) && (*s))
			s++;
	}
	return (cnt);
}