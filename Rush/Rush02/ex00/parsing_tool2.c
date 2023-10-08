/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:21:21 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/06 17:15:22 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long long	ch_pkey(long long key, long long *pr_key)
{
	while (*pr_key)
	{
		if (key == *pr_key)
			return (1);
		pr_key++;
	}
	return (0);
}

long long	is_printable(char a)
{
	if (a <= 31 || a >= 127)
		return (0);
	return (1);
}
