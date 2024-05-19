/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:19 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/19 18:07:31 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_philo
{
	int	die_time;
	int start_time;
	int	cnt_eat;
	int	status;
	int	id;
	
	pthread_t t;
	int lfork;
	int rfork;
	
}	t_philo;


typedef struct s_info
{
	int	cnt_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	cnt_loop;
	int end;
	
	t_philo	*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	pthread_mutex_t time;
}	t_info;

int		ft_atoi(const char *str);
void	error_print(char *error);
void	init_main(t_info *philo_info, int argc, char **argv);
void	init_info(t_info *philo_info, int argc, char **argv);
void	init_forks(t_info *philo_info);
void	init_philo(t_info *philo_info);
int		get_time(void);


#endif