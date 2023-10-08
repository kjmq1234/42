/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:09:48 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/06 17:15:13 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long long	my_atoi(char *str)
{
	long long	result;
	long long	minus;
	long long	idx;

	idx = 0;
	minus = 1;
	result = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
	{
		idx++;
	}
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = (result * 10) + (str[idx] - '0');
		idx++;
	}
	return (result * minus);
}

void	array_reset(char *str, long long size)
{
	long long	count;

	count = 0;
	while (count < size)
	{
		str[count] = 0;
		count++;
	}
}

char	*str_to_value(char *str)
{
	char		*res;
	long long	idx;

	res = (char *)malloc(sizeof(char) * 100);
	idx = 0;
	while (*str != ':')
		str++;
	str++;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (is_printable(*str))
		{
			res[idx] = *str;
			idx++;
		}
		str++;
	}
	res[idx] = '\0';
	return (res);
}
