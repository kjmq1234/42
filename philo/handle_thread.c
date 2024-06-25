/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:11:43 by jammin            #+#    #+#             */
/*   Updated: 2024/06/25 23:53:20 by jammin           ###   ########.fr       */
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
		ft_usleep(philo->info->time_eat);
    while (philo->info->philo_is_die == 0)
    {
		eat(philo);
		// if (philo->cnt_eat == philo->info->cnt_loop)
		// {
		// 	pthread_mutex_lock(&philo->info->monitoring);
		// 	philo->info->philo_is_comple++;
		// 	pthread_mutex_unlock(&philo->info->monitoring);
		// 	break ;
		// }
		sleeping(philo);
		print_mutex(philo->info, "is thinking", philo->id);
    }
    return (NULL);
}

void    monitering(t_info *philo_info)
{
    int i;
	long long current;

    while (philo_info->philo_is_die == 0)
    {
        if (philo_info->cnt_loop != 0 && philo_info->philo_is_comple == philo_info->cnt_philo)
            break;
		i = 0;
		while (i < philo_info->cnt_philo)
		{
			current = get_time();
			if (current > philo_info->philos[i].die_time)
			{
				print_mutex(philo_info, "died", philo_info->philos[i].id);
				pthread_mutex_lock(&philo_info->die);
				philo_info->philo_is_die = 1;
				pthread_mutex_unlock(&philo_info->die);
				break ;
			}
			i++;
		}
    }
}

int	check_die(t_philo *philo)
{
	int current;

	current = get_time();
	if (current == -1)
		error_print("gettimeofday() FAILURE\n");
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