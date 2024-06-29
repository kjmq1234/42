/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:41:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/29 19:45:22 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	flag;

	sum = 0;
	flag = 1;
	if (*str == '\0')
		return (-1);
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
		return (-1);
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

void	ft_usleep(int ms)
{
	long	start;
	long	end;

	start = get_time();
	end = start + ms;
	while (get_time() < end)
		usleep(100);
}

void	ft_pthread_mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
		error_print("pthread_mutex_lock() FAILURE\n");
}

void	ft_pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
		error_print("pthread_mutex_unlock() FAILURE\n");
}
