/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:16:44 by jaemikim          #+#    #+#             */
/*   Updated: 2024/05/04 03:17:38 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_n(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		if (*s == '\n')
			len--;
		s++;
	}
	return (len);
}

void	exit_open(void)
{
	printf("잘못된 파일명입니다.");
	exit(1);
}

char	**copy_map(char **map, t_game info)
{
	unsigned long long	i;
	char				**copy;

	i = 0;
	copy = (char **) malloc(sizeof(char *) * info.height);
	if (!copy)
		exit(1);
	while (i < info.height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

void	free_maps(char **map, t_game info)
{
	unsigned long long	i;

	i = 0;
	while (i < info.height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_move_cnt(t_game *game_info)
{
	ft_putstr_fd("이동횟수: ", 1);
	ft_putnbr_fd(game_info->move_cnt, 1);
	ft_putstr_fd("\n", 1);
}
