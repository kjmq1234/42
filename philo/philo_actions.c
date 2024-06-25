/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:39:05 by jammin            #+#    #+#             */
/*   Updated: 2024/06/26 03:31:48 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
		pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
		pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
	}

}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->info->monitoring);
	philo->die_time = get_time() + philo->info->time_die;
	philo->cnt_eat++;
	pthread_mutex_unlock(&philo->info->monitoring);
	print_mutex(philo->info, "is eating", philo->id);
	ft_usleep(philo->info->time_eat);
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo->info, "is sleeping", philo->id);
	ft_usleep(philo->info->time_sleep);
}