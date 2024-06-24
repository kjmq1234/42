/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:19 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/25 04:09:04 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_philo
{
	int	die_time;
	int start_time;
	int	cnt_eat;
	int	status;
	int	id;
	
	pthread_t tid;
	int lfork;
	int rfork;
	struct s_info *info;
}	t_philo;


typedef struct s_info
{
	int	cnt_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	cnt_loop;
	int philo_is_die;
	int philo_is_comple;
	
	t_philo	*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	pthread_mutex_t monitoring;
}	t_info;

int		ft_atoi(const char *str);
void	error_print(char *error);
void	init_main(t_info *philo_info, int argc, char **argv);
void	init_info(t_info *philo_info, int argc, char **argv);
void	init_forks(t_info *philo_info);
void	init_philo(t_info *philo_info);
int		get_time(void);
void	ft_usleep(int time);
void	print_mutex(t_info *philo_info, char *str, int id);
void    *routine(void *arg);
void	start_thread(t_info *philo_info);
void	philo_routine(t_philo *philo);
void 	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);

#endif