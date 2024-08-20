/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:19 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/29 19:20:21 by jaemikim         ###   ########.fr       */
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
	int				die_time;
	int				cnt_eat;
	int				status;
	int				id;
	pthread_t		tid;
	int				lfork;
	int				rfork;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				cnt_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				cnt_loop;
	int				philo_is_die;
	int				start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	monitoring;
}	t_info;

int		ft_atoi(const char *str);
void	error_print(char *error);
void	init_main(t_info *philo_info, int argc, char **argv);
void	init_info(t_info *philo_info, int argc, char **argv);
void	init_forks(t_info *philo_info);
void	init_philo(t_info *philo_info);
int		get_time(void);
void	ft_usleep(int time);
void	print_mutex(t_info *philo_info, char *str, int id, int isdie);
void	*routine(void *arg);
void	start_thread(t_info *philo_info);
void	philo_routine(t_philo *philo);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	monitering(t_info *philo_info);
void	free_malloc(t_info *philo_info);
void	destroy_mutex(t_info *philo_info);
int		check_die(t_philo *philo);
int		check_comple(t_philo *philo, int *philo_is_comple);
void	ft_pthread_mutex_lock(pthread_mutex_t *mutex);
void	ft_pthread_mutex_unlock(pthread_mutex_t *mutex);

#endif