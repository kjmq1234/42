/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:29:17 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/10 03:02:29 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_mapinfo(char *file, t_game *map_info)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_open();
	line = get_next_line(fd);
	if ((!line) || (line[0] == '\0'))
		exit(EXIT_FAILURE);
	map_info->width = ft_strlen_n(line);
	free(line);
	map_info->height++;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (map_info->width != ft_strlen_n(line))
		{
			ft_putendl_fd("Error\n맵이 직사각형이 아닙니다.", 1);
			exit(EXIT_FAILURE);
		}
		free(line);
		map_info->height++;
	}
}

void	parse_map_element(char **map, t_game *map_info)
{
	unsigned long long	hei;
	unsigned long long	wid;

	hei = 0;
	wid = 0;
	while (hei < map_info->height)
	{
		while (wid < map_info->width)
		{
			mapping_map_element(map, map_info, hei, wid);
			wid++;
		}
		hei++;
		wid = 0;
	}
}

void	read_map(char *file, char **map, t_game map_info)
{
	char				*str;
	int					fd;
	unsigned long long	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_open();
	while (i < map_info.height)
	{
		str = get_next_line(fd);
		map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	close(fd);
}

void	mapping_map_element(char **map, t_game *map_info, \
unsigned long long hei, unsigned long long wid)
{
	if (map[hei][wid] == 'E')
	{
		map_info->e_num++;
		map_info->e_y = hei;
		map_info->e_x = wid;
	}
	else if (map[hei][wid] == 'C')
		map_info->c_num++;
	else if (map[hei][wid] == 'P')
	{
		map_info->p_num++;
		map_info->p_y = hei;
		map_info->p_x = wid;
	}
	else if ((map[hei][wid] != '0') && (map[hei][wid] != '1'))
	{
		ft_putendl_fd("Error\n맵에 잘못된 값이 있습니다.", 1);
		exit(EXIT_FAILURE);
	}
}
