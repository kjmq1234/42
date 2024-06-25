/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:41:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/26 02:54:44 by jaemikim         ###   ########.fr       */
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


void ft_usleep(int ms)
{
    long start;
    long end;

	start = get_time();
	end = start + ms;
    while (get_time() < end)
        usleep(100);
}

