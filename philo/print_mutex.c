/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:43:40 by jammin            #+#    #+#             */
/*   Updated: 2024/06/29 19:22:24 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_info *philo_info, char *str, int id, int isdie)
{
	int	current;

	current = get_time();
	ft_pthread_mutex_lock(&philo_info->print);
	ft_pthread_mutex_lock(&philo_info->die);
	if (philo_info->philo_is_die != 0)
	{
		ft_pthread_mutex_unlock(&philo_info->die);
		ft_pthread_mutex_unlock(&philo_info->print);
		return ;
	}
	if (isdie == 1)
		philo_info->philo_is_die = 1;
	printf("%d %d %s\n", current - philo_info->start_time, id, str);
	ft_pthread_mutex_unlock(&philo_info->die);
	ft_pthread_mutex_unlock(&philo_info->print);
}
