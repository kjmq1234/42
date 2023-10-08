/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:32:42 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 18:20:53 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_min(void)
{
	char	min[11];

	min[0] = '-';
	min[1] = '2';
	min[2] = '1';
	min[3] = '4';
	min[4] = '7';
	min[5] = '4';
	min[6] = '8';
	min[7] = '3';
	min[8] = '6';
	min[9] = '4';
	min[10] = '8';
	write(1, min, 11);
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		print_min();
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	n = nb % 10 + 48;
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	write(1, &n, 1);
}
/*
int	main(void)
{
	ft_putnbr(42);
}
*/
