/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:42:00 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/29 14:41:34 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_error_printer(void);
int	skyscraper_main(int n, int *arr);

int	word_count(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == 32)
			i++;
		str++;
	}
	if ((i + 1) % 4 == 0)
		return (i + 1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int	argv_index;
	int	arr_index;
	int	*arr;

	arr = (int *) malloc(sizeof(int) * word_count(argv[1]));
	argv_index = 0;
	arr_index = 0;
	if ((argc != 2) || (word_count(argv[1]) == 0))
		return (ft_error_printer());
	while (arr_index < word_count(argv[1]))
	{
		if ((argv[1][argv_index] >= '0') && (argv[1][arr_index] <= '9'))
			arr[arr_index++] = argv[1][argv_index++] - '0';
		else
			return (ft_error_printer());
		if (argv[1][argv_index] == 32)
			argv_index++;
		else if (arr_index == word_count(argv[1]))
			break ;
		else
			return (ft_error_printer());
	}
	skyscraper_main(word_count(argv[1]) / 4, arr);
}
