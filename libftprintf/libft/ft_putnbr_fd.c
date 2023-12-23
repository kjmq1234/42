/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:08:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:54:11 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_nbr(int n, int fd, int *len);

int	ft_putnbr_fd(int n, int fd)
{
	int len;

	len  = 0;
	if (fd < 1)
		return (0);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		len++;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	print_nbr(n, fd, &len);
	return (len);
}

static void	print_nbr(int n, int fd, int *len)
{
	char	tmp;

	if (n / 10 != 0)
		print_nbr(n / 10, fd, len);
	tmp = n % 10 + '0';
	*len += write(fd, &tmp, 1);
}
