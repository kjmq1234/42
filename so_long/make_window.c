/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:50:07 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/18 20:57:39 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window_main(t_game *game_info)
{
	game_info->mlx_ptr = mlx_init();
	game_info->win_ptr = mlx_new_window(game_info->mlx_ptr, 500, 500, "lingard");
	mlx_loop(game_info->mlx_ptr);
}

// void	*mlx_ptr(t_game *info)
// {
//     info->mlx_ptr = mlx_init();
// 	info->win_ptr = mlx_new_window(info->mlx_ptr, 500, 500, "my_mlx");
// 	info->tile = mlx_xpm_file_to_image(info->mlx_ptr, "./images/land.xpm", 5, 1);
// 	info->wall = mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall.xpm", 5, 1);

// 	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->tile, 0, 0);

// 	mlx_loop(info->mlx_ptr);
// 	return (0);
// }