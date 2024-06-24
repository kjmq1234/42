/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:39:05 by jammin            #+#    #+#             */
/*   Updated: 2024/06/25 04:12:09 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	take_forks(philo);
	drop_forks(philo);
	philo->cnt_eat++;
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
}