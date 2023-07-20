/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:42:12 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 18:17:34 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int first, int second)
{
	char	fir_buf[2];
	char	sec_buf[2];

	fir_buf[0] = first / 10 + 48;
	fir_buf[1] = first % 10 + 48;
	sec_buf[0] = second / 10 + 48;
	sec_buf[1] = second % 10 + 48;
	if (first < second)
	{
		write(1, fir_buf, 2);
		write(1, " ", 1);
		write(1, sec_buf, 2);
		if (first != 98)
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	while (first != 100)
	{
		print(first, second);
		second++;
		if (second == 100)
		{
			second = 0;
			first++;
		}
	}	
}
/*
int	main(void)
{
	ft_print_comb2();
}
*/
