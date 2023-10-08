/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:12:20 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/03 13:40:31 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	temp;

	i = 0;
	temp = min;
	if (min >= max)
		return (0);
	range[0] = (int *) malloc(sizeof(int) * (max - min));
	if (!range[0])
		return (-1);
	while (min < max)
		range[0][i++] = min++;
	return (max - temp);
}
