/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:43:40 by jammin            #+#    #+#             */
/*   Updated: 2024/06/26 03:00:29 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_info *philo_info, char *str, int id)
{
    int current;
    
    current = get_time();
  
    if (current == -1)
        error_print("gettimeofday() FAILURE\n");
    if (philo_info->philo_is_die != 0)
    {
        return ;
    }
	
    pthread_mutex_lock(&philo_info->print);
    printf("%d %d %s\n", current - philo_info->start_time, id, str);
    pthread_mutex_unlock(&philo_info->print);
}