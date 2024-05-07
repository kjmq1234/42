/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_dfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:42:30 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/07 23:58:20 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_item_valid(char **map, t_game *map_info, int x, int y)
{
	const int	mvx[4] = {-1, 1, 0, 0};
	const int	mvy[4] = {0, 0, -1, 1};
	int			nx;
	int			ny;
	int			cnt;

	if ((map[y][x] == '1') || (map[y][x] == 'V'))
		return ;
	if (map[y][x] == 'C')
	{
		map[y][x] = 'V';
		map_info->dfs_coin++;
	}
	map[y][x] = 'V';
	cnt = 0;
	while (cnt < 4)
	{
		nx = x + mvx[cnt];
		ny = y + mvy[cnt];
		search_item_valid(map, map_info, nx, ny);
		cnt++;
	}
}

void	search_item_valid_e(char **map, t_game *map_info, int x, int y)
{
	const int	mvx[4] = {-1, 1, 0, 0};
	const int	mvy[4] = {0, 0, -1, 1};
	int			nx;
	int			ny;
	int			cnt;

	if ((map[y][x] == '1') || (map[y][x] == 'V'))
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		map_info->dfs_e++;
		return ;
	}
	map[y][x] = 'V';
	cnt = 0;
	while (cnt < 4)
	{
		nx = x + mvx[cnt];
		ny = y + mvy[cnt];
		search_item_valid_e(map, map_info, nx, ny);
		cnt++;
	}
}
