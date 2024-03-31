#include "so_long.h"

void	init_mapinfo(t_map* map_info)
{
	map_info->height = 0;
	map_info->width = 0;
	map_info->p_num = 0;
	map_info->c_num = 0;
	map_info->e_num = 0;
}

void	init_dfs(t_dfs* dfs_info)
{
	dfs_info->e_num = 0;
	dfs_info->get_coin = 0;
	dfs_info->p_num = 0;
}