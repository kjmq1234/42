/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:21:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 12:26:13 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex(unsigned int n, int fd, int *len);

int	ft_puthex_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (fd < 1)
		return (-1);
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n *= -1;
	}
	print_hex(n, fd, &len);
	return (len);
}

static void	print_hex(unsigned int n, int fd, int *len)
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
