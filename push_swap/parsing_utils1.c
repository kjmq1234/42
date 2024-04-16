/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:59:39 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/16 21:45:11 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_arg_main(int argc, char **argv, t_push_swap *set)
{
	int	*array;
	int	count;

	count = count_args(argc, argv);
	array = (int *) malloc(sizeof(int) * count);
	if (!array)
		exit(1) ;
	parsing_arg(argc, argv, array);
	arg_into_stack(set, array, count);
	duplicate_check(array, count, set);
	add_index(array, set);
	free(array);
	return (count);
}

void	arg_into_stack(t_push_swap *set, int *array, int scale)
{
	int	i;

	i = 0;
	while (i < scale)
	{
		push_bottom(set->a, array[i], 0);
		i++;
	}
}

void	parsing_arg(int argc, char **argv, int *array)
{
	char	**avs;
	int		i;
	int		j;
	int		c;

	j = 0;
	i = 1;
	while (i < argc)
	{
		avs = ft_split(argv[i], ' ');
		c = 0;
		if (!*avs)
			error_print();
		while (avs[c])
		{
			array[j] = ft_atoi(avs[c]);
			free(avs[c]);
			j++;
			c++;
		}
		free(avs);
		i++;
	}
}

int	count_args(int argc, char **argv)
{
	int		avs;
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		avs = wordcnt(argv[i], ' ');
		cnt += avs;
		i++;
	}
	return (cnt);
}

void	duplicate_check(int *array, int count, t_push_swap* set)
{
	int	i;
	int	j;
	int	swap_cnt;

	swap_cnt = 0;
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
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
		exit_sorted_numbers(array, set);
}
