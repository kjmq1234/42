#include "so_long.h"

void	init_data(t_game *game_info)
{
	game_info->mlx_ptr = NULL;
	game_info->win_ptr = NULL;
	game_info->height = 0;
	game_info->width = 0;
	game_info->p_num = 0;
	game_info->c_num = 0;
	game_info->e_num = 0;
	game_info->map = NULL;
}