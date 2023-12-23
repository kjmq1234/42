/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:21:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 03:25:25 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex(int n, int fd, int *len);

int	ft_puthex_fd(int n, int fd)
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
	print_hex(n, fd, &len);
	return (len);
}

static void	print_hex(int n, int fd, int *len)
{
	char	tmp;

	if (n / 16 != 0)
		print_hex(n / 16, fd, len);
    if (n % 16 < 10)
    	tmp = n % 16 + '0';
    else
    	tmp = n % 16 - 10 + 'a';
	*len += write(fd, &tmp, 1);
}
