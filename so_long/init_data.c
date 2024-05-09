/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:02:50 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/10 01:25:16 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_game *game_info)
{
	int	img_wid;
	int	img_hei;

	game_info->mlx_ptr = mlx_init();
	game_info->win_ptr = NULL;
	game_info->height = 0;
	game_info->width = 0;
	game_info->p_num = 0;
	game_info->c_num = 0;
	game_info->e_num = 0;
	game_info->map = NULL;
	game_info->img_coin = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/coin.xpm", &img_wid, &img_hei);
	game_info->img_player = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/player.xpm", &img_wid, &img_hei);
	game_info->img_ground = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/ground.xpm", &img_wid, &img_hei);
	game_info->img_exit1 = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/exit.xpm", &img_wid, &img_hei);
	game_info->img_exit2 = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/exit1.xpm", &img_wid, &img_hei);
	game_info->img_wall = mlx_xpm_file_to_image(game_info->mlx_ptr, \
	"./imgs/wall.xpm", &img_wid, &img_hei);
	init_data2(game_info);
}

void	init_data2(t_game *game_info)
{
	game_info->move_cnt = 0;
	game_info->get_coin = 0;
	game_info->dfs_coin = 0;
	game_info->dfs_e = 0;
}
