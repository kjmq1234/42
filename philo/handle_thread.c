/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:11:43 by jammin            #+#    #+#             */
/*   Updated: 2024/06/29 19:21:05 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thread(t_info *philo_info)
{
	int	i;

	i = 0;
	philo_info->start_time = get_time();
	while (i < philo_info->cnt_philo)
	{
		philo_info->philos[i].die_time = \
		philo_info->start_time + philo_info->time_die;
		if (pthread_create(&philo_info->philos[i].tid, \
		NULL, &routine, &philo_info->philos[i]))
			error_print("pthread_create() FAILURE\n");
		i++;
	}
	monitering(philo_info);
	i = 0;
	while (i < philo_info->cnt_philo)
	{
		if (pthread_join(philo_info->philos[i].tid, NULL))
			error_print("pthread_join() FAILURE\n");
		i++;
	}
	destroy_mutex(philo_info);
	free_malloc(philo_info);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->info->time_eat);
	while (1)
	{
		ft_pthread_mutex_lock(&philo->info->die);
		if (philo->info->philo_is_die == 1)
		{
			ft_pthread_mutex_unlock(&philo->info->die);
			break ;
		}
		ft_pthread_mutex_unlock(&philo->info->die);
		eat(philo);
		if (philo->info->cnt_philo != 1)
		{
			sleeping(philo);
			print_mutex(philo->info, "is thinking", philo->id, 0);
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	monitering(t_info *philo_info)
{
	int	i;
	int	philo_is_comple;

	philo_is_comple = 0;
	while (1)
	{
		i = 0;
		while (i < philo_info->cnt_philo)
		{
			check_comple(&philo_info->philos[i], &philo_is_comple);
			if (check_die(&philo_info->philos[i]) == 1)
				return ;
			i++;
		}
		if (philo_info->cnt_loop != -1 && \
		philo_is_comple == philo_info->cnt_philo)
		{
			ft_pthread_mutex_lock(&philo_info->die);
			philo_info->philo_is_die = 1;
			ft_pthread_mutex_unlock(&philo_info->die);
			break ;
		}
	}
}

int	check_die(t_philo *philo)
{
	int	current;

	current = get_time();
	if (current == -1)
		error_print("gettimeofday() FAILURE\n");
	ft_pthread_mutex_lock(&philo->info->monitoring);
	if (current > philo->die_time)
	{
		ft_pthread_mutex_unlock(&philo->info->monitoring);
		print_mutex(philo->info, "died", philo->id, 1);
		return (1);
	}
	ft_pthread_mutex_unlock(&philo->info->monitoring);
	return (0);
}

int	check_comple(t_philo *philo, int *philo_is_comple)
{
	if (philo->info->cnt_loop != -1 && philo->cnt_eat >= philo->info->cnt_loop)
	{
		ft_pthread_mutex_lock(&philo->info->monitoring);
		if (philo->status == 0)
		{
			*philo_is_comple += 1;
		}
		ft_pthread_mutex_unlock(&philo->info->monitoring);
		ft_pthread_mutex_lock(&philo->info->monitoring);
		philo->status = 1;
		ft_pthread_mutex_unlock(&philo->info->monitoring);
	}
	return (0);
}
