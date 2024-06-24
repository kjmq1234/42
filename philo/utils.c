/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:41:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/25 00:47:31 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	flag;

	sum = 0;
	flag = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		sum = sum * 10 + (*str - 48);
		str++;
	}
	return (flag * sum);
}

int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		error_print("gettimeofday() FAILURE\n");
		return (0);
	}
	return ((tv.tv_sec * (int) 1000) + (tv.tv_usec / 1000));
}


void	ft_usleep(int time)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}
