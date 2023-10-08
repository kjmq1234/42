/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:07:06 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/06 18:39:55 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchr(char *value)
{
	long long	len;

	len = 0;
	while (*(value + len))
		len++;
	write(1, value, len);
}

void	printer(t_dict *s_tail, long long nb)
{
	t_dict	*s_temp;

	if (nb > 0)
	{
		s_temp = s_tail;
		while (s_temp->key > nb)
			s_temp = s_temp->s_left;
		if (nb > 100)
			printer(s_temp, nb / s_temp->key);
		ft_putchr(s_temp->value);
		write(1, " ", 1);
		printer(s_temp, nb % s_temp -> key);
	}
}
