/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:28:31 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/04 03:16:14 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_a(t_game *game_info)
{
	move_player(game_info, 0);
}

void	press_s(t_game *game_info)
{
	move_player(game_info, 3);
}

void	press_d(t_game *game_info)
{
	move_player(game_info, 1);
}

void	press_w(t_game *game_info)
{
	move_player(game_info, 2);
}
