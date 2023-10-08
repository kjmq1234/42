/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:34:27 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/03 16:05:02 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *arr)
{
	char	temp;
	int		i;

	i = 0;
	while (i < 10)
	{
		temp = *arr++ + 48;
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	invalid(int *arr, int x)
{
	int	row;

	row = 0;
	while (row < x)
	{
		if (arr[x] == arr[row] || x == row
			|| x - arr[x] == row - arr[row] || x + arr[x] == arr[row] + row)
			return (0);
		row++;
	}
	return (1);
}

void	recursive(int *arr, int x, int *count)
{
	int	y;

	y = 0;
	if (x == 10)
	{
		print(arr);
		*count += 1;
		return ;
	}
	while (y < 10)
	{
		arr[x] = y;
		if (invalid(arr, x))
			recursive(arr, x + 1, count);
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	x;
	int	count;

	count = 0;
	x = 0;
	while (x < 10)
		arr[x++] = 0;
	recursive(arr, 0, &count);
	return (count);
}
