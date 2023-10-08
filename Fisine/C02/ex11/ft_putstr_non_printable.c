/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:49:54 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/25 23:16:48 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ten_tosixteen(unsigned char str)
{
	unsigned char	non[3];

	non[0] = '\\';
	if (str / 16 >= 10)
		non[1] = 'a' + (str / 16) - 10;
	else
		non[1] = '0' + (str / 16);
	if (str % 16 >= 10)
		non[2] = 'a' + (str % 16) - 10;
	else
		non[2] = '0' + (str % 16);
	write(1, non, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(((unsigned char) *str >= 32) && ((unsigned char) *str <= 126)))
			ten_tosixteen((unsigned char) *str);
		else
			write(1, str, 1);
		str++;
	}
}
