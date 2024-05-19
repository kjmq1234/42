/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:54:48 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/19 15:56:55 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_print(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}