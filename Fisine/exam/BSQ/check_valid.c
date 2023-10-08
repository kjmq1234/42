/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:43:49 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/10 11:11:47 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	check_valid(t_inp *map)
{
	if (map->empty == map->full || map->empty == map->obstacle)
		errprt();
	else if (map->full == map->obstacle)
		errprt();
}
