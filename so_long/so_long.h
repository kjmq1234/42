#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
// # include "libftprintf/ft_printf.h"
# include "get_next_line_bonus.h"
#include <fcntl.h>




#include <stdio.h>




# define X_EVENT_PRESS_KEY 2
# define X_EVENT_RED_X 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_game
{
	unsigned long long		height;
	unsigned long long		width;
	unsigned long long		c_num;
	unsigned				e_num;
	unsigned				p_num;
	unsigned				p_x;
	unsigned				p_y;
	char					**map;
	void	*mlx_ptr;
	void	*win_ptr;
} t_game;

char			**malloc_map(t_game map_info);
void			read_map(char *file, char **map, t_game map_info);
size_t			ft_strlen_n(const char *s);
void			parse_map_element(char **map, t_game* map_info);
int				valid_check(char **map, t_game* map_info);
int				element_valid(t_game map_info);
int				edge_valid(char **map, t_game map_info);
int				road_valid(char **map,t_game map_info);
int				name_valid(char* name);
void			exit_open(void);
unsigned int	search_item_valid(char **map,t_game map_info, int x, int y, char item);
char**			copy_map(char** map, t_game info);
void			free_maps(char** map, t_game info);
void			parsing_main(char *argv, t_game *map_info);
void			init_data(t_game *game_info);
void			make_window_main(t_game *game_info);
void			parse_mapinfo(char *file, t_game* map_info);

#endif