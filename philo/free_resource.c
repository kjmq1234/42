/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:14:45 by jammin            #+#    #+#             */
/*   Updated: 2024/06/25 22:35:38 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_malloc(t_info *philo_info)
{
	free(philo_info->philos);
	free(philo_info->forks);
}

void	destroy_mutex(t_info *philo_info)
{
	int	i;

	i = 0;
	while (i < philo_info->cnt_philo)
	{
		if (pthread_mutex_destroy(&philo_info->forks[i]))
			error_print("mutex destroy 실패입니다.");
		i++;
	}
	if (pthread_mutex_destroy(&philo_info->print))
		error_print("mutex destroy 실패입니다.");
	if (pthread_mutex_destroy(&philo_info->monitoring))
		error_print("mutex destroy 실패입니다.");
	if (pthread_mutex_destroy(&philo_info->die))
		error_print("mutex destroy 실패입니다.");
}