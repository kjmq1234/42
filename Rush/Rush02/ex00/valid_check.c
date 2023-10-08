/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:47:13 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/06 17:16:15 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long long	dict_rule(char *str)
{
	long long	flag;

	flag = 0;
	while (*str != ':')
	{
		if (*str >= '0' && *str <= '9')
			flag = 1;
		str++;
	}
	if (*str == ':' && flag == 1)
	{
		flag = 2;
		str++;
	}
	while (*str)
	{
		if (is_printable(*str) && flag == 2 && *str != ' ')
			flag++;
		str++;
	}
	if (flag >= 3)
		return (1);
	return (0);
}

long long	ch_rdunt(t_dict *s_head, long long vkey)
{
	t_dict	*s_temp;

	s_temp = s_head;
	while (s_temp != NULL)
	{
		if (s_temp->key == vkey)
			return (1);
		s_temp = s_temp->s_right;
	}
	return (0);
}

void	init_pk(long long *pr_key)
{
	int		i;
	int		j;

	i = -1;
	j = 30;
	while (++i < 21)
		*(pr_key + i) = i;
	while (j <= 100)
	{
		pr_key[i++] = j;
		j += 10;
	}
	pr_key[i++] = 1000;
	pr_key[i++] = 1000000;
	pr_key[i] = 1000000000;
}

long long	is_pravate(long long num, long long *pr_key)
{
	int	idx;

	idx = 0;
	while (idx < 32)
	{
		if (num == pr_key[idx])
			return (1);
		idx++;
	}
	return (0);
}
