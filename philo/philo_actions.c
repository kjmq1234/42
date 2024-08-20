/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:39:05 by jammin            #+#    #+#             */
/*   Updated: 2024/06/29 19:22:59 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->info->cnt_philo == 1)
	{
		ft_pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id, 0);
		ft_pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
		ft_usleep(philo->info->time_die);
		return ;
	}
	else if (philo->id % 2 == 1)
	{
		ft_pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id, 0);
		ft_pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id, 0);
	}
	else
	{
		ft_pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_mutex(philo->info, "has taken a fork", philo->id, 0);
		ft_pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_mutex(philo->info, "has taken a fork", philo->id, 0);
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
		ft_pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	}
	else
	{
		ft_pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
		ft_pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
	}
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	if (philo->info->cnt_philo != 1)
	{
		ft_pthread_mutex_lock(&philo->info->monitoring);
		philo->die_time = get_time() + philo->info->time_die;
		philo->cnt_eat++;
		ft_pthread_mutex_unlock(&philo->info->monitoring);
		print_mutex(philo->info, "is eating", philo->id, 0);
		ft_usleep(philo->info->time_eat);
		drop_forks(philo);
	}
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo->info, "is sleeping", philo->id, 0);
	ft_usleep(philo->info->time_sleep);
}
