#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("맵을 넣어주세요.");
		return (0);
	}
	if (name_valid(argv[1]) != 0)
	{
		printf("잘못된 이름입니다.");
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
		exit(1);

	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
