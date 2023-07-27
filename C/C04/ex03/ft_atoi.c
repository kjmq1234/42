/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:56:31 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/26 21:06:06 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	long long int	to_int;
	int				sign;

	to_int = 0;
	sign = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			to_int = to_int * 10 + (*str - 48);
		}
		else if (((*str == '+') || (*str == '-')) && (to_int == 0))
		{
			if (*str == '-')
				sign *= -1;
		}
		else
			break ;
		str++;
	}
	return ((int) sign * to_int);
}
