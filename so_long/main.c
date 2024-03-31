#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("맵을 넣어주세요.");
		return (0);
	}
	t_map map_info;
	char **map;

	init_mapinfo(&map_info);
	parse_mapinfo(argv[1], &map_info);
	map = malloc_map(map_info);
	read_map(argv[1], map, map_info);
	parse_map_element(map, &map_info);
	if(!valid_check(map, &map_info))
	{
		free(map);
		return (0);
	}
}
