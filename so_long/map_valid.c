#include "so_long.h"

int	valid_check(char **map, t_map* map_info)
{
	if ((!edge_valid(map, *map_info)) | (!element_valid(*map_info)) | ((!road_valid(map, *map_info))))
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

unsigned int	search_item_valid(char **map,t_map map_info, int x, int y, char item)
{
	int	cnt;

	cnt = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] != 'V')
	{
		if (map[y][x] == item)
		{
			map[y][x] = 'V';
			return (1);
		}
		map[y][x] = 'V';
		cnt = 0;
		cnt += search_item_valid(map, map_info, x + 1, y, item);
		cnt += search_item_valid(map, map_info, x - 1, y, item);
		cnt += search_item_valid(map, map_info, x, y + 1, item);
		cnt += search_item_valid(map, map_info, x, y - 1, item);
		return (cnt);
	}
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

int road_valid(char **map, t_map map_info)
{
	char	**e_map;
	char	**c_map;
	char	**p_map;

	e_map = copy_map(map, map_info);
	c_map = copy_map(map, map_info);
	p_map = copy_map(map, map_info);
	
	if ((search_item_valid(e_map, map_info, map_info.p_x, map_info.p_y, 'E') != map_info.e_num) || \
	(search_item_valid(c_map, map_info, map_info.p_x, map_info.p_y, 'C') != map_info.c_num) || \
	(search_item_valid(p_map, map_info, map_info.p_x, map_info.p_y, 'P') != map_info.p_num))
	{
		printf("잘못된 경로가 있습니다.");
		return (0);
	}
	return (1);
}