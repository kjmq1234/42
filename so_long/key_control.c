/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:31:27 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/04 03:17:54 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_x_button(t_game *game_info)
{
	unsigned long long	i;

	i = 0;
	free_maps(game_info->map, *game_info);
	exit(EXIT_SUCCESS);
}

int	move_key(int key, t_game *game_info)
{
	if (key == KEY_ESC)
	{
		free_maps(game_info->map, *game_info);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_A)
		press_a(game_info);
	if (key == KEY_D)
		press_d(game_info);
	if (key == KEY_S)
		press_s(game_info);
	if (key == KEY_W)
		press_w(game_info);
	return (1);
}
