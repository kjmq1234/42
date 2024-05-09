/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:04:43 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/10 03:46:07 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leak()
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	t_game 	game_info;
	
	if (argc != 2)
	{
		ft_putendl_fd("Error\n 하나의 맵을 넣어주세요.", 1);
		exit(EXIT_FAILURE);
	}
	if (name_valid(argv[1]) != 0)
	{
		ft_putendl_fd("Error\n잘못된 파일명입니다.", 1);
		exit(EXIT_FAILURE);
	}
	atexit(leak);
	init_data(&game_info);
	parsing_main(argv[1], &game_info);
	make_window_main(&game_info);
}
