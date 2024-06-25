/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:39:05 by jammin            #+#    #+#             */
/*   Updated: 2024/06/25 23:53:11 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	take_forks(philo);
	eat(philo);
	drop_forks(philo);
	sleeping(philo);
	print_mutex(philo->info, "is thinking", philo->id);
}

void	take_forks(t_philo *philo)
{
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id);
}

void	drop_forks(t_philo *philo)
{
		pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
		pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	philo->die_time = get_time() + philo->info->time_die;
	print_mutex(philo->info, "is eating", philo->id);
	ft_usleep(philo->info->time_eat);
	philo->cnt_eat++;
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo->info, "is sleeping", philo->id);
	ft_usleep(philo->info->time_sleep);
}