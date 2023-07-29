/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:56:15 by minjacho          #+#    #+#             */
/*   Updated: 2023/07/29 14:25:13 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	has_same_num_check(const int size, const int *arr)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[size - 1])
			return (1);
		i++;
	}
	return (0);
}

int	left_height_check(const int n, const int *arr, const int expect_val)
{
	int	i;
	int	prev;
	int	real;

	i = 0;
	prev = 0;
	real = 0;
	while (i < n)
	{
		if (prev < arr[i])
		{
			prev = arr[i];
			real++;
		}
		i++;
	}
	return (real == expect_val);
}

int	right_height_check(const int n, const int *arr, const int expect_val)
{
	int	i;
	int	prev;
	int	real;

	i = n - 1;
	prev = 0;
	real = 0;
	while (i >= 0)
	{
		if (prev < arr[i])
		{
			prev = arr[i];
			real++;
		}
		i--;
	}
	return (real == expect_val);
}

int	h_check(int n, int *arr, int left, int right)
{
	int	left_bool;
	int	right_bool;

	left_bool = left_height_check(n, arr, left);
	right_bool = right_height_check(n, arr, right);
	return (left_bool && right_bool);
}
