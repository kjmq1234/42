/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:56:15 by minjacho          #+#    #+#             */
/*   Updated: 2023/07/31 22:14:05 by jaemikim         ###   ########.fr       */
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

int	empty_check(const int n, int idx, const int arr_val, const int expect_val)
{
	if (expect_val == n)
	{
		if (arr_val != idx + 1)
			return (0);
	}
	else if (expect_val == 1)
	{	
		if (idx == 0 && arr_val != n)
			return (0);
	}
	else
	{
		if (arr_val > n + 1 - expect_val + idx)
			return (0);
	}
	return (1);
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
	int	len;
	int	left_bool;
	int	right_bool;

	len = 0;
	while (arr[len] != 0)
		len++;
	if (len == n)
	{
		left_bool = left_height_check(n, arr, left);
		right_bool = right_height_check(n, arr, right);
	}
	else
	{
		left_bool = empty_check(n, len - 1, arr[len - 1], left);
		right_bool = empty_check(n, n - len, arr[len - 1], right);
	}
	return ((left_bool) && (right_bool));
}
