/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:40:49 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 03:47:27 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_ptr(unsigned long long n, int fd, int *len);

int	ft_putptr_fd(void *n, int fd)
{
	int len;

	len  = 0;
	if (fd < 1)
		return (0);
	len += write(1, "0x", 2);
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	print_ptr((unsigned long long) n, fd, &len);
	return (len);
}

static void	print_ptr(unsigned long long n, int fd, int *len)
{
	char	tmp;

	if (n / 16 != 0)
		print_ptr(n / 16, fd, len);
	if (n % 16 < 10)
    	tmp = n % 16 + '0';
    else
    	tmp = n % 16 - 10 + 'a';
	*len += write(fd, &tmp, 1);
}
