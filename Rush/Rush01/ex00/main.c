/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:42:00 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/30 15:29:06 by yejyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_error_printer(void);
int	skyscraper_main(int n, int *arr);
int	ft_free(int *ptr);

int	word_count(char *str)
{
	int	tab_count;
	int	num_count;

	tab_count = 0;
	num_count = 0;
	while (*str)
	{
		if (*str == 32)
			tab_count++;
		else if (*str >= '0' && *str <= '9')
			num_count++;
		else
			return (0);
		str++;
	}
	if ((tab_count + 1) % 4 == 0 && num_count - tab_count == 1)
		return (num_count);
	else
		return (0);
}

int	check_active(char **argv, int wcnt, int *arr)
{
	int	argv_i;
	int	arr_i;

	argv_i = 0;
	arr_i = 0;
	while (arr_i < wcnt)
	{
		if ((argv[1][argv_i] >= '1') && ((argv[1][arr_i] <= wcnt / 4) + '0'))
			arr[arr_i++] = argv[1][argv_i++] - '0';
		else
			return (0);
		if (argv[1][argv_i] == 32)
			argv_i++;
		else if (arr_i == wcnt)
			break ;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	wcnt;

	wcnt = word_count(argv[1]);
	if ((argc != 2) || (wcnt == 0))
		return (ft_error_printer());
	arr = (int *) malloc(sizeof(int) * wcnt);
	if (!arr)
		return (ft_error_printer());
	if (!check_active(argv, wcnt, arr))
		ft_error_printer();
	else
		skyscraper_main(wcnt / 4, arr);
	ft_free(arr);
}
