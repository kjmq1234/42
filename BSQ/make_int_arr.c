/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:16:29 by kyumkim           #+#    #+#             */
/*   Updated: 2023/08/10 11:15:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	first_str_check(char *buff, t_inp *inp)
{
	int		linelen;
	int		idx;
	int		num;

	idx = 0;
	num = 0;
	linelen = strsize(buff);
	if (linelen < 4)
		errprt();
	while (idx < linelen - 3)
	{
		if (buff[idx] < '0' || buff[idx] > '9')
			errprt();
		num = num * 10 + (buff[idx] - 48);
		idx++;
	}
	if (num == 0)
		errprt();
	inp->col = num;
	inp->empty = buff[idx++];
	inp->obstacle = buff[idx++];
	inp->full = buff[idx];
	check_valid(inp);
}

int	strsize(char *str)
{
	int		ret;

	ret = 0;
	while (*str != '\0')
	{
		str++;
		ret++;
	}
	return (ret);
}

void	makearr(char **input, t_inp *inp)
{
	int	**arr;
	int	idx;
	int	idx2;

	idx = 0;
	arr = malloc(sizeof(int *) * inp->col);
	while (idx < inp->col)
	{
		arr[idx] = malloc(sizeof(int) * inp->row);
		idx2 = 0;
		while (input[idx + 1][idx2] != '\0')
		{
			if (input[idx + 1][idx2] != inp->empty &&
				input[idx + 1][idx2] != inp->obstacle)
				errprt();
			else if (input[idx + 1][idx2] == inp->empty)
				arr[idx][idx2] = 1;
			else
				arr[idx][idx2] = 0;
			idx2++;
		}
		idx++;
	}
	inp->map = arr;
}

void	rowcolsame(char **input, t_inp *inp)
{
	int	idx;
	int	row;

	idx = 1;
	if (input[idx] == 0 && inp->col != 0)
		errprt();
	row = strsize(input[idx]);
	idx++;
	while (input[idx] != 0)
	{
		if (row != strsize(input[idx]))
			errprt();
		idx++;
	}
	inp->row = row;
	if (inp->col != idx - 1)
		errprt();
}
