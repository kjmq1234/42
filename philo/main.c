/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:39:20 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:31 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	t_info	philo_info;

	// atexit(check);
	if ((argc < 5) || (argc > 6))
		error_print("인자의 갯수를 정확하게 입력해주세요");
	init_main(&philo_info, argc, argv);
	start_thread(&philo_info);
}
