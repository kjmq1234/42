/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:59:39 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/09 21:32:19 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg_main(int argc, char **argv, t_push_swap *set)
{
	int	*array;
	int	count;

	count = count_args(argc, argv);
	array = (int *) malloc(sizeof(int) * count);
	if (!array)
		return ;
	parsing_arg(argc, argv, array);
	arg_into_stack(set, array, count);
	duplicate_check(array, count);
	add_index(array, set->a);
}

void	arg_into_stack(t_push_swap *set, int *array, int scale)
{
	int	i;

	i = 0;
	while (i < scale)
	{
		push_bottom(set->a, array[i]);
		i++;
	}
}

void	parsing_arg(int argc, char **argv, int *array)
{
	char	**avs;
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		avs = ft_split(argv[i], ' ');
		if (!*avs)
			error_print();
		while (*avs)
		{
			array[j] = ft_atoi(*avs);
			j++;
			avs++;
		}
		i++;
	}
}

int	count_args(int argc, char **argv)
{
	char	**avs;
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		avs = ft_split(argv[i], ' ');
		while (*avs)
		{
			cnt++;
			avs++;
		}
		i++;
	}
	return (cnt);
}

void	duplicate_check(int *array, int count)
{
	int	i;
	int	j;
	int	swap_cnt;

	swap_cnt = 0;
	i = 0;
	while (i < count)
	{
		j = i;
		while (j < count - 1)
		{
			if (array[j] == array[j + 1])
				error_print();
			if (array[j] > array[j + 1])
			{
				ft_swap(&array[j], &array[j + 1]);
				swap_cnt++;
			}
			j++;
		}
		i++;
	}
	if (!swap_cnt)
		exit_sorted_numbers(array);
}
