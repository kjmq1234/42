/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:11:43 by jammin            #+#    #+#             */
/*   Updated: 2024/06/25 04:11:30 by jammin           ###   ########.fr       */
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
        if (pthread_create(&philo_info->philos[i].tid, NULL, &routine, &philo_info->philos[i]))
            error_print("pthread_create() FAILURE\n");
        i++;
    }
    i = 0;
    while (i < philo_info->cnt_philo)
    {
        if (pthread_join(philo_info->philos[i].tid, NULL))
            error_print("pthread_join() FAILURE\n");
        i++;
    }
}

// TODO: 철학자 한 명이면 예외처리

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    // if (philo->id % 2)
    //     ft_usleep(1000);
    while (philo->info->philo_is_die == 0)
    {
        philo_routine(philo);
		pthread_mutex_lock(&philo->info->monitoring);
		if (philo->cnt_eat == philo->info->cnt_loop)
		{
			philo->info->philo_is_comple++;
			pthread_mutex_unlock(&philo->info->monitoring);
			break ;
		}
		pthread_mutex_unlock(&philo->info->monitoring);

    }
    return (NULL);
}