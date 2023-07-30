/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:42:29 by minjacho          #+#    #+#             */
/*   Updated: 2023/07/30 12:17:00 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	n_by_n_printer(int n, int *arr);
int		has_same_num_check(const int size, const int *arr);
int		h_check(int n, int *arr, int left, int right);
int		*get_col_from_map(int idx, int *map, const int n);
int		*get_row_from_map(int idx, int *map, const int n);
void	ft_free(int *ptr);
int		ft_error_printer(void);

int	sky_check(int idx, int *map, const int n, const int *cond)
{
	int	*r_arr;
	int	*c_arr;
	int	r;
	int	c;
	int	has_same;

	r_arr = get_row_from_map(idx, map, n);
	c_arr = get_col_from_map(idx, map, n);
	r = 1;
	c = 1;
	has_same = 0;
	if (has_same_num_check(idx - ((idx / n) * n) + 1, r_arr))
		has_same = 1;
	if (has_same_num_check(idx / n + 1, c_arr))
		has_same = 1;
	if (!has_same)
	{
		r = h_check(n, r_arr, cond[idx / n + 2 * n], cond[idx / n + 3 * n]);
		c = h_check(n, c_arr, cond[idx % n], cond[idx % n + n]);
	}
	ft_free(r_arr);
	ft_free(c_arr);
	return (!has_same && r && c);
}

int	recur_skyscraper(int i, int *map, const int n, const int *cond)
{
	int	height;
	int	no_result;

	no_result = 1;
	if (i == n * n)
	{
		n_by_n_printer(n, map);
		return (0);
	}
	height = n;
	while (height >= 1)
	{
		map[i] = height;
		if (sky_check(i, map, n, cond))
			no_result *= recur_skyscraper(i + 1, map, n, cond);
		if (!no_result)
			return (no_result);
		height--;
	}
	return (no_result);
}

int	skyscraper_main(int n, int *arr)
{
	int	no_result;
	int	*map;
	int	i;

	map = (int *)malloc((n * n) * sizeof(int));
	if (!map)
		ft_error_printer();
	i = 0;
	while (i < n * n)
	{
		map[i] = 0;
		i++;
	}
	no_result = recur_skyscraper(0, map, n, arr);
	if (no_result)
		return (ft_error_printer());
	return (0);
}
