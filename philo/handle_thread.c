/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:11:43 by jammin            #+#    #+#             */
/*   Updated: 2024/06/26 02:13:11 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thread(t_info *philo_info)
{
    int	i;

    i = 0;
    while (i < philo_info->cnt_philo)
    {
        philo_info->philos[i].start_time = get_time();
		philo_info->philos[i].die_time = philo_info->philos[i].start_time + philo_info->time_die;

        if (pthread_create(&philo_info->philos[i].tid, NULL, &routine, &philo_info->philos[i]))
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

// TODO: 철학자 한 명이면 예외처리

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
    while (1)
    {
		eat(philo);
		pthread_mutex_lock(&philo->info->die);
		if (philo->info->philo_is_die == 1)
		{
			pthread_mutex_unlock(&philo->info->die);
			break ;
		}
		pthread_mutex_unlock(&philo->info->die);
		sleeping(philo);
		ft_usleep(1); // 스케줄 관리를 위한 
		print_mutex(philo->info, "is thinking", philo->id);
    }
    return (NULL);
}

void    monitering(t_info *philo_info)
{
    int i;
	int philo_is_comple;

	philo_is_comple = 0;
    while (1)
    {
		i = 0;
		while (i < philo_info->cnt_philo)
		{
			pthread_mutex_lock(&philo_info->die);
			if (check_die(&philo_info->philos[i], &philo_is_comple) == 1)
			{
				pthread_mutex_unlock(&philo_info->die);
				return ;
			}
			i++;
			pthread_mutex_unlock(&philo_info->die);
		}
		if (philo_info->cnt_loop != -1 && philo_is_comple == philo_info->cnt_philo)
		{
			pthread_mutex_lock(&philo_info->die);
			philo_info->philo_is_die = 1;
			pthread_mutex_unlock(&philo_info->die);
			break ;
		}
    }
}

int	check_die(t_philo *philo, int *philo_is_comple)
{
	int current;

	current = get_time();
	if (current == -1)
		error_print("gettimeofday() FAILURE\n");
	if (philo->info->cnt_loop != -1 && philo->cnt_eat >= philo->info->cnt_loop)
	{
		if (philo->status == 0)
			*philo_is_comple += 1;
		philo->status = 1;
		return (0);
	}
	if (current > philo->die_time)
	{
		print_mutex(philo->info, "died", philo->id);
		pthread_mutex_lock(&philo->info->die);
		philo->info->philo_is_die = 1;
		pthread_mutex_unlock(&philo->info->die);
		return (1);
	}
	return (0);
}