/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:12:13 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/07 01:57:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
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