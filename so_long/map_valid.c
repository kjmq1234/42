#include "so_long.h"

int	valid_check(char **map, t_map* map_info)
{
	if ((!edge_valid(map, *map_info)) | (!element_valid(*map_info)) )//| if (!road_valid()))
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
			if ((map[hei][wid] != '1') && ((hei == 0) || (hei == map_info.height - 1) || (wid == map_info.width) || (wid == 0)))
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

int	road_valid(char **map,t_map map_info)
{
	// t_dfs	dfs_info;
	// int		x[4];
	// int		y[4];
	int		i;

	i = 0;
	//init_dfs(&dfs_info, x, y);
	map[0][0] = 1;
	map_info.height = map_info.height;
	return (0);
}

