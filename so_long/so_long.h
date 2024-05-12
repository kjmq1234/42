/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:58:57 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/12 23:51:05 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>

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
	unsigned long long		e_num;
	unsigned long long		p_num;
	unsigned long long		p_x;
	unsigned long long		p_y;
	unsigned long long		e_x;
	unsigned long long		e_y;
	char					**map;
	void					*mlx_ptr;
	void					*win_ptr;
	int						move_cnt;
	void					*img_ground;
	void					*img_wall;
	void					*img_coin;
	void					*img_player;
	void					*img_exit1;
	void					*img_exit2;
	int						img_wid;
	int						img_hei;
	unsigned long long		get_coin;
	unsigned long long		dfs_coin;
	unsigned long long		dfs_e;
}	t_game;

void			read_map(char *file, char **map, t_game map_info);
size_t			ft_strlen_n(const char *s);
void			parse_map_element(char **map, t_game *map_info);
int				valid_check(char **map, t_game *map_info);
int				element_valid(t_game map_info);
int				edge_valid(char **map, t_game map_info);
int				road_valid(char **map, t_game *map_info);
int				name_valid(char *name);
void			exit_open(void);
void			search_item_valid(char **map, t_game *map_info, int x, int y);
void			search_item_valid_e(char **map, t_game *map_info, int x, int y);
char			**copy_map(char **map, t_game info);
void			free_maps(char **map, t_game info);
void			parsing_main(char *argv, t_game *map_info);
void			init_data(t_game *game_info);
void			make_window_main(t_game *game_info);
void			parse_mapinfo(char *file, t_game *map_info);
void			setting_img(t_game *game_info);
int				press_x_button(t_game *game_info);
int				move_key(int key, t_game *game_info);
void			press_a(t_game *game_info);
void			press_d(t_game *game_info);
void			press_s(t_game *game_info);
void			press_w(t_game *game_info);
void			print_move_cnt(t_game *game_info);
void			move_player(t_game *game_info, int sig);
void			set_player(t_game *game_info, int x, int y);
void			set_pixel(t_game *game_info, unsigned long long wid, \
unsigned long long hei);
void			set_pixel2(t_game *game_info, unsigned long long wid, \
unsigned long long hei);
void			set_player_e(t_game *game_info, int x, int y);
void			mapping_map_element(char **map, t_game *map_info, \
unsigned long long hei, unsigned long long wid);
void			set_player_e2(t_game *game_info, int x, int y);
void			init_data2(t_game *game_info);
void			check_empty(char *line);

#endif