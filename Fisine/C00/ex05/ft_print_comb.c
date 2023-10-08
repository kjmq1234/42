/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:56 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 18:34:59 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int soo)
{	
	char	buf[3];

	buf[0] = soo / 100 + 48;
	buf[1] = soo / 10 % 10 + 48;
	buf[2] = soo % 10 + 48;
	if ((buf[0] < buf[1]) && (buf[1] < buf[2]))
	{
		if (buf[0] == '7')
			write(1, buf, 3);
		else
		{
			write(1, buf, 3);
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int	soo;

	soo = 0;
	while (soo != 1000)
	{
		print(soo);
		soo++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
