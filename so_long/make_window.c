#include "so_long.h"


void	*mlx_ptr(t_game *info)
{
    info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 500, 500, "my_mlx");
	info->tile = mlx_xpm_file_to_image(info->mlx_ptr, "./images/land.xpm", 5, 1);
	info->wall = mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall.xpm", 5, 1);

	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->tile, 0, 0);

	mlx_loop(info->mlx_ptr);
	return (0);
}