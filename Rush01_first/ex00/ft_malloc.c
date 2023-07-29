/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:40:09 by minjacho          #+#    #+#             */
/*   Updated: 2023/07/29 11:43:55 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	*get_row_from_map(int idx, int *map, const int n)
{
	int	i;
	int	*result;
	int	result_i;

	result_i = 0;
	i = (idx / n) * n;
	result = (int *)malloc(sizeof(int) * (idx - i + 1));
	if (!result)
	{
		write(2, "ERROR : malloc error occured!\n", 30);
		return (0);
	}
	while (i <= idx)
	{
		result[result_i] = map[i];
		i++;
		result_i++;
	}
	return (result);
}

int	*get_col_from_map(int idx, int *map, const int n)
{
	int	i;
	int	*result;
	int	result_i;

	result_i = 0;
	i = idx % n;
	result = (int *)malloc(sizeof(int) * (idx / n + 1));
	if (!result)
	{
		write(2, "ERROR : malloc error occured!\n", 30);
		return (0);
	}
	while (i <= idx)
	{
		result[result_i] = map[i];
		result_i++;
		i += n;
	}
	return (result);
}

void	ft_free(int *ptr)
{
	if (ptr)
		free(ptr);
	ptr = 0;
}
