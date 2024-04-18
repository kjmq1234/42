/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:41:46 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/18 18:25:56 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	long long	sum;
	int			flag;

	sum = 0;
	flag = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	if (!*str)
		error_print();
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_print();
		sum = sum * 10 + (*str - 48);
		str++;
	}
	if ((sum > 2147483647) || (sum < -2147483648))
		error_print();
	return ((int) flag * sum);
}
