/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:21:32 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/12 23:48:11 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_check(char **map, t_game *map_info)
{
	if ((!edge_valid(map, *map_info)) | (!element_valid(*map_info)))
		return (0);
	if (!road_valid(map, map_info))
		return (0);
	return (1);
}

int	element_valid(t_game map_info)
{
	if (map_info.height == 0)
	{
		ft_putendl_fd("Error\n빈 맵입니다.", 1);
		return (0);
	}
	if ((map_info.c_num == 0) || (map_info.p_num != 1) || (map_info.e_num != 1))
	{
		if (map_info.c_num == 0)
			ft_putstr_fd("Error\n수집품이 없습니다.\n", 1);
		if (map_info.e_num == 0)
			ft_putstr_fd("Error\n출구가 없습니다.\n", 1);
		if (map_info.e_num > 1)
			ft_putstr_fd("Error\n출구가 여러개입니다.\n", 1);
		if (map_info.p_num == 0)
			ft_putstr_fd("Error\n시작지점이 없습니다.\n", 1);
		if (map_info.p_num > 1)
			ft_putstr_fd("Error\n시작지점이 여러개입니다.\n", 1);
		return (0);
	}
	return (1);
}

int	edge_valid(char **map, t_game map_info)
{
	unsigned long long	hei;
	unsigned long long	wid;

	hei = 0;
	wid = 0;
	while (hei < map_info.height)
	{
		while (wid < map_info.width)
		{
			if ((map[hei][wid] != '1') && ((hei == 0) || \
			(hei == map_info.height - 1) || (wid == map_info.width - 1) \
			|| (wid == 0)))
			{
				ft_putstr_fd("Error\n벽에 문제가 있습니다.\n", 1);
				return (0);
			}
			wid++;
		}
		hei++;
		wid = 0;
	}
	return (1);
}

int	name_valid(char *name)
{
	char	*dot;

	dot = name;
	if (ft_strrchr(name, '/') != NULL)
	{
		dot = ft_strrchr(name, '/');
		dot++;
	}
	if (ft_strncmp(dot, ".ber\0", 5) == 0)
		return (1);
	if (ft_strrchr(name, '.') == NULL)
		return (1);
		dot = ft_strrchr(name, '.');
	return (ft_strncmp(dot, ".ber\0", 5));
}

int	road_valid(char **map, t_game *map_info)
{
	char	**c_map;
	char	**e_map;

	c_map = copy_map(map, *map_info);
	e_map = copy_map(map, *map_info);
	search_item_valid(c_map, map_info, map_info->p_x, map_info->p_y);
	search_item_valid_e(e_map, map_info, map_info->p_x, map_info->p_y);
	if ((map_info->dfs_coin != map_info->c_num) || (map_info->dfs_e != 1))
	{
		ft_putendl_fd("Error\n잘못된 경로가 있습니다.", 1);
		free_maps(c_map, *map_info);
		free_maps(e_map, *map_info);
		return (0);
	}
	free_maps(c_map, *map_info);
	free_maps(e_map, *map_info);
	return (1);
}
