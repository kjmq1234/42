/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:21:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 12:26:10 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_uhex(unsigned int n, int fd, int *len);

int	ft_putuhex_fd(unsigned int n, int fd)
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
	print_uhex(n, fd, &len);
	return (len);
}

static void	print_uhex(unsigned int n, int fd, int *len)
{
	char	tmp;

	if (n / 16 != 0)
		print_uhex(n / 16, fd, len);
	if (n % 16 < 10)
		tmp = n % 16 + '0';
	else
		tmp = n % 16 - 10 + 'A';
	*len += write(fd, &tmp, 1);
}
