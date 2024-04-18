#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game 	game_info;
	
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
	init_data(&game_info);
	parsing_main(argv[1], &game_info);
	make_window_main(&game_info);
}
