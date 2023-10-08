/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:40:09 by minjacho          #+#    #+#             */
/*   Updated: 2023/07/31 21:42:59 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*get_row_from_map(int idx, int *map, const int n)
{
	int	i;
	int	*result;
	int	result_i;

	result_i = 0;
	i = (idx / n) * n;
	result = (int *)malloc(sizeof(int) * (idx - i + 2));
	if (!result)
		return (0);
	while (i <= idx)
	{
		result[result_i] = map[i];
		i++;
		result_i++;
	}
	result[result_i] = 0;
	return (result);
}

int	*get_col_from_map(int idx, int *map, const int n)
{
	int	i;
	int	*result;
	int	result_i;

	result_i = 0;
	i = idx % n;
	result = (int *)malloc(sizeof(int) * (idx / n + 2));
	if (!result)
		return (0);
	while (i <= idx)
	{
		result[result_i] = map[i];
		result_i++;
		i += n;
	}
	result[result_i] = 0;
	return (result);
}

void	ft_free(int *ptr)
{
	if (ptr)
		free(ptr);
}
