/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:40:49 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 12:59:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	print_ptr(unsigned long long n, int fd, int *len);

int	ft_putptr_fd(void *n, int fd)
{
	int	len;
	int	return_num;

	len = 0;
	if (fd < 1)
		return (0);
	return_num = write(1, "0x", 2);
	if ((print_ptr((unsigned long long) n, fd, &len) == -1) \
	|| (return_num == -1))
		return (-1);
	return (len + return_num);
}

static int	print_ptr(unsigned long long n, int fd, int *len)
{
	char	tmp;
	int		return_num;

	if (n / 16 != 0)
	{
		return_num = print_ptr(n / 16, fd, len);
		if (return_num == -1)
			return (-1);
	}
	if (n % 16 < 10)
		tmp = n % 16 + '0';
	else
		tmp = n % 16 - 10 + 'a';
	return_num = write(fd, &tmp, 1);
	if (return_num == -1)
		return (-1);
	*len += 1;
	return (1);
}
