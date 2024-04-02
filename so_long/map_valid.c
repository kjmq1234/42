#include "so_long.h"

int	valid_check(char **map, t_map* map_info)
{
	t_dfs dfs_info;

	init_dfs(&dfs_info);
	if ((!edge_valid(map, *map_info)) | (!element_valid(*map_info)) | (!road_valid(map, *map_info, dfs_info, map_info->p_x, map_info->p_y, 0)))
		return(0);
	return (1);
}

int	element_valid(t_map map_info)
{
	if ((map_info.c_num == 0) || (map_info.p_num != 1) || (map_info.e_num != 1))
	{
		if (map_info.c_num == 0)
			printf("Error\n수집품이 없습니다.\n");
		if (map_info.e_num == 0)
			printf("Error\n출구가 없습니다.\n");
		if (map_info.e_num > 1)
			printf("Error\n출구가 여러개입니다.\n");
		if (map_info.p_num == 0)
			printf("Error\n시작지점이 없습니다.\n");
		if (map_info.p_num > 1)
			printf("Error\n시작지점이 여러개입니다.\n");
		return (0);
	}
	return (1);
}

int	edge_valid(char **map, t_map map_info)
{
	unsigned long long	hei;
	unsigned long long	wid;

	hei = 0;
	wid = 0;
	while (hei < map_info.height)
	{
		while (wid < map_info.width)
		{
			if ((map[hei][wid] != '1') && ((hei == 0) || (hei == map_info.height - 1) || (wid == map_info.width - 1) || (wid == 0)))
			{
				printf("Error\n벽에 문제가 있습니다.\n");
				return (0);
			}
			wid++;
		}
		hei++;
		wid = 0;
	}
	return (1);
}

int	road_valid(char **map,t_map map_info, t_dfs dfs_info, int x, int y, int i)
{
	const int	x_move[4] = {1, -1, 0, 0};
	const int	y_move[4] = {0, 0, 1, -1};

	printf("x: %d y: %d i: %d\nc: %d e: %d p: %d\n\n", x, y, dfs_info.get_coin, dfs_info.e_num, dfs_info.p_num);
	if (i > 3)
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'c')
		dfs_info.get_coin++;
	if (map[y][x] == 'e')
		dfs_info.e_num++;
	if (map[y][x] == 'p')
		dfs_info.p_num++;
	map[y][x] = '1';
	if ((dfs_info.e_num == 1) && (dfs_info.p_num == 1) && (dfs_info.get_coin == map_info.c_num))
		return (1);
	if (road_valid(map, map_info, dfs_info, x + x_move[i], y + y_move[i], i))
		return (1);
	else
		road_valid(map, map_info, dfs_info, x + x_move[i], y + y_move[i], i + 1);
	return (0);
}

int name_valid(char* name)
{
	char*	dot;
	if (ft_strrchr(name, '.') == 0)
		return (1);
		dot = ft_strrchr(name, '.');
	return(ft_strncmp(dot, ".ber\0", 5));
}