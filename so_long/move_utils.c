/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:32:30 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/08 00:12:08 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game_info, int sig)
{
	const int	x_array[4] = {-1, 1, 0, 0};
	const int	y_array[4] = {0, 0, -1, 1};
	int			x;
	int			y;

	x = game_info->p_x + x_array[sig];
	y = game_info->p_y + y_array[sig];
	if (game_info->map[y][x] == '1')
		return ;
	if (game_info->map[y][x] == 'e')
		exit(1);
	if (game_info->map[y][x] == 'C')
	{
		game_info->get_coin++;
		if (game_info->c_num == game_info->get_coin)
			game_info->map[game_info->e_y][game_info->e_x] = 'e';
	}
	if (game_info->map[y][x] == 'E')
		set_player_e(game_info, x, y);
	else
		set_player(game_info, x, y);
}

void	set_player(t_game *game_info, int x, int y)
{
	if (game_info->map[game_info->p_y][game_info->p_x] == 'O')
		game_info->map[game_info->p_y][game_info->p_x] = 'E';
	else
		game_info->map[game_info->p_y][game_info->p_x] = '0';
	game_info->p_x = x;
	game_info->p_y = y;
	game_info->map[y][x] = 'P';
	setting_img(game_info);
	game_info->move_cnt++;
	print_move_cnt(game_info);
}

void	set_player_e(t_game *game_info, int x, int y)
{
	game_info->map[game_info->p_y][game_info->p_x] = '0';
	game_info->p_x = x;
	game_info->p_y = y;
	game_info->map[y][x] = 'O';
	setting_img(game_info);
	game_info->move_cnt++;
	print_move_cnt(game_info);
}
