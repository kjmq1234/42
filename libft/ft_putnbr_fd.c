/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:08:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/31 21:30:10 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		numlen(int n);
void	print_nbr(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 1)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	print_nbr(n, fd);
}

void	print_nbr(int n, int fd)
{
	char	tmp;

	if (n / 10 != 0)
		print_nbr(n / 10, fd);
	tmp = n % 10 + '0';
	write(fd, &tmp, 1);
}
