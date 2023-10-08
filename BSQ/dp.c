/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:38:14 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/10 11:17:37 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int x, int y, int **map)
{
	int	m1;

	m1 = map[y - 1][x];
	if (map[y - 1][x - 1] < m1)
		m1 = map[y - 1][x - 1];
	if (map[y][x - 1] < m1)
		m1 = map[y][x - 1];
	return (m1);
}

void	print(t_inp *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->col)
	{
		x = 0;
		while (x < map->row)
		{
			if (map->map[y][x] == 0)
				write(1, &map->obstacle, 1);
			else if ((map->y - map->size + 1 <= y && y <= map->y)
				&& (map->x - map->size +1 <= x && x <= map->x))
				write(1, &map->full, 1);
			else
				write(1, &map->empty, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ar_min(int x, int y, int size, t_inp *map)
{
	map->x = x;
	map->y = y;
	map->size = size;
}

void	dp(t_inp *map)
{
	int	x;
	int	y;

	map->size = 0;
	y = 0;
	while (y < map->col)
	{
		x = 0;
		while (x < map->row)
		{
			if ((x == 0 || y == 0) && map->map[y][x] > map->size)
				ar_min(x, y, 1, map);
			if ((x != 0 && y != 0) && map->map[y][x] == 1)
			{
				map->map[y][x] = min(x, y, map->map) + 1;
				if (map->map[y][x] > map->size)
					ar_min(x, y, map->map[y][x], map);
			}
			x++;
		}
		y++;
	}
}
/*
   int	main(void)
   {
   struct s_inp	map;
   int				**a;

   a = malloc(sizeof(int *) * 5);
   for(int i=0; i<5; i++)
   {
   a[i] = malloc(sizeof(int) * 5);
   }
   a[0][0] = 1;
   a[0][1] = 1;
   a[0][2] = 1;
   a[0][3] = 1;
   a[0][4] = 1;
   a[1][0] = 1;
   a[1][1] = 1;
   a[1][2] = 1;
   a[1][3] = 1;
   a[1][4] = 1;
   a[2][0] = 1;
   a[2][1] = 1;
   a[2][2] = 1;
   a[2][3] = 1;
   a[2][4] = 1;
   a[3][0] = 1;
   a[3][1] = 1;
   a[3][2] = 1;
   a[3][3] = 1;
   a[3][4] = 1;
   a[4][0] = 1;
   a[4][1] = 1;
   a[4][2] = 1;
   a[4][3] = 1;
   a[4][4] = 1;
   map.map = a;
   map.row = 5;
   map.col = 5;
   dp(&map);
   print(&map);
   printf("x : %d y: %d size: %d", map.x, map.y, map.size);
   }
   */
