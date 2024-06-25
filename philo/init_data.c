/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:02:39 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/26 01:51:27 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_main(t_info *philo_info, int argc, char **argv)
{
    init_info(philo_info, argc, argv);
    init_philo(philo_info);
    
    // printf("%d %d %d %d %d", philo_info->cnt_philo, philo_info->time_die, philo_info->time_eat, philo_info->time_sleep, philo_info->cnt_loop);
}

void	init_info(t_info *philo_info, int argc, char **argv)
{
    philo_info->cnt_philo = ft_atoi(argv[1]);
    philo_info->time_die = ft_atoi(argv[2]);
    philo_info->time_eat = ft_atoi(argv[3]);
    philo_info->time_sleep = ft_atoi(argv[4]);
    philo_info->cnt_loop = -1;
    philo_info->philo_is_die = 0;
    if (philo_info->cnt_philo < 0 || philo_info->time_die < 0 \
    || philo_info->time_eat < 0 || philo_info->time_sleep < 0)
            error_print("0보다 큰 인자를 넣어주세요.");
    if (argc == 6)
    {
        philo_info->cnt_loop = ft_atoi(argv[5]);
        if (philo_info->cnt_loop < 0)
            error_print("0 이상의 인자를 넣어주세요.");
    }
	init_forks(philo_info);

}

void	init_forks(t_info *philo_info)
{
	int	i;

	i = 0;
	philo_info->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * philo_info->cnt_philo);
	if (!philo_info->forks)
		error_print("메모리 할당 실패입니다.");
	while (i < philo_info->cnt_philo)
	{
		if (pthread_mutex_init(&philo_info->forks[i], NULL))
			error_print("mutex 초기화 실패입니다.");
		i++;
	}
	if (pthread_mutex_init(&philo_info->print, NULL))
		error_print("mutex 초기화 실패입니다.");
	if (pthread_mutex_init(&philo_info->monitoring, NULL))
		error_print("mutex 초기화 실패입니다.");
	if (pthread_mutex_init(&philo_info->die, NULL))
		error_print("mutex 초기화 실패입니다.");
}

void	init_philo(t_info *philo_info)
{
	int	i;

	i = 0;
	philo_info->philos = (t_philo *) malloc(sizeof(t_philo) * philo_info->cnt_philo);
	if (!philo_info->philos)
		error_print("메모리 할당 실패입니다.");
	while (i < philo_info->cnt_philo)
	{
		philo_info->philos[i].id = i + 1;
		philo_info->philos[i].cnt_eat = 0;
		philo_info->philos[i].lfork = i;
		philo_info->philos[i].rfork = (i + 1) % philo_info->cnt_philo;
		philo_info->philos[i].status = 0;
		philo_info->philos[i].die_time = get_time() + philo_info->time_die;
		philo_info->philos[i].info = philo_info;
		i++;
	}
}