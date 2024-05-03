/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:50:07 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/04 03:08:56 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window_main(t_game *game_info)
{
	game_info->win_ptr = mlx_new_window(game_info->mlx_ptr, \
	game_info->width * 64, game_info->height * 64, "lingard");
	setting_img(game_info);
	mlx_hook(game_info->win_ptr, X_EVENT_PRESS_KEY, 0, move_key, game_info);
	mlx_hook(game_info->win_ptr, X_EVENT_RED_X, 0, &press_x_button, game_info);
	mlx_loop(game_info->mlx_ptr);
}

void	setting_img(t_game *game_info)
{
	unsigned long long	hei;
	unsigned long long	wid;

	hei = 0;
	wid = 0;
	mlx_clear_window(game_info->mlx_ptr, game_info->win_ptr);
	while (hei < game_info->height)
	{
		while (wid < game_info->width)
		{
			set_pixel(game_info, wid, hei);
			wid++;
		}
		hei++;
		wid = 0;
	}
}

void	set_pixel(t_game *game_info, unsigned long long wid, \
unsigned long long hei)
{
	mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
	game_info->img_ground, wid * 64, hei * 64);
	if (game_info->map[hei][wid] == 'E')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_exit1, wid * 64, hei * 64);
	else if (game_info->map[hei][wid] == 'e')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_exit2, wid * 64, hei * 64);
	else if (game_info->map[hei][wid] == 'O')
	{
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_exit1, wid * 64, hei * 64);
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_player, wid * 64, hei * 64);
	}
	else
		set_pixel2(game_info, wid, hei);
}

void	set_pixel2(t_game *game_info, unsigned long long wid, \
unsigned long long hei)
{
	if (game_info->map[hei][wid] == 'o')
	{
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_exit1, wid * 64, hei * 64);
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_player, wid * 64, hei * 64);
	}
	if (game_info->map[hei][wid] == 'C')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_coin, wid * 64, hei * 64);
	if (game_info->map[hei][wid] == '1')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_wall, wid * 64, hei * 64);
	if (game_info->map[hei][wid] == 'P')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, \
		game_info->img_player, wid * 64, hei * 64);
}
