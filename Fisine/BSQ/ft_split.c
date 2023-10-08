/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:24:25 by kyumkim           #+#    #+#             */
/*   Updated: 2023/08/10 11:03:37 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_split(char *buff)
{
	char	**ret;
	int		ret_idx;
	int		idx1;
	int		idx2;

	ret = (char **)malloc(sizeof(char *) * (how_many_strs(buff) + 1));
	if (ret == 0)
		errprt();
	ret_idx = 0;
	idx1 = 0;
	while (ret_idx < how_many_strs(buff))
	{
		while (buff[idx1] != '\0' && buff[idx1] == '\n')
			idx1++;
		idx2 = idx1;
		while (buff[idx2] != '\0' && buff[idx2] != '\n')
			idx2++;
		ret[ret_idx] = putstr(buff, idx1, idx2);
		idx1 = idx2;
		ret_idx++;
	}
	ret[ret_idx] = 0;
	return (ret);
}

char	*putstr(char *str, int idx1, int idx2)
{
	char	*ret;
	int		retidx;

	ret = (char *)malloc(idx2 - idx1 + 1);
	retidx = 0;
	while (idx1 < idx2)
	{
		ret[retidx] = str[idx1];
		retidx++;
		idx1++;
	}
	ret[retidx] = '\0';
	return (ret);
}

int	how_many_strs(char *str)
{
	int	ret;
	int	flag;

	ret = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (flag == 0 && *str != '\n')
		{
			flag = 1;
			ret++;
		}
		else if (*str == '\n')
			flag = 0;
		str++;
	}
	return (ret);
}
