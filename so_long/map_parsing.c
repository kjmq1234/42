/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:27:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/10 01:29:42 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_main(char *argv, t_game *map_info)
{
	parse_mapinfo(argv, map_info);
	map_info->map = (char **) malloc((map_info->height + 1) * (sizeof(char *)));
	if (!map_info->map)
		exit(EXIT_FAILURE);
	read_map(argv, map_info->map, *map_info);
	parse_map_element(map_info->map, map_info);
	if (!valid_check(map_info->map, map_info))
		exit(EXIT_FAILURE);
}
