#include "so_long.h"

void	parse_mapinfo(char *file, t_map* map_info)
{
    int		fd;
	char*	line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_open();
	line = get_next_line(fd);
	if (!line)
		exit(1);
	map_info->width = ft_strlen_n(line);
	map_info->height++;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (map_info->width != ft_strlen_n(line))
		{
			printf("맵이 직사각형이 아닙니다.");
			exit(1);
		}
		map_info->height++;
	}
}

char	**malloc_map(t_map map_info)
{
	char**				map;
	unsigned long long	i;

	i = 0;
	map = (char**) malloc(map_info.height * (sizeof(char*)));
	if (!map)
		exit(1);
	while (i < map_info.height)
	{
		map[i] = (char*) malloc(map_info.width * sizeof(char) + 1);
		if (!map[i])
			exit(1);
		i++;
	}
	return (map);
}

void	parse_map_element(char **map, t_map* map_info)
{
	unsigned long long	hei;
	unsigned long long	wid;

	hei = 0;
	wid = 0;
	while (hei < map_info->height)
	{
		while (wid < map_info->width)
		{
			if (map[hei][wid] == 'E')
				map_info->e_num++;
			if (map[hei][wid] == 'C')
				map_info->c_num++;
			if (map[hei][wid] == 'P')
			{
				map_info->p_num++;
				map_info->p_y = hei;
				map_info->p_x = wid;
			}
			wid++;
		}
		hei++;
		wid = 0;
	}
}

void	read_map(char *file, char **map, t_map map_info)
{
	int					fd;
	unsigned long long	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_open();
	while(i < map_info.height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
}