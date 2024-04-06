/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 12:26:00 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_unbr(unsigned int n, int fd, int *len);

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (fd < 1)
		return (-1);
	print_unbr(n, fd, &len);
	return (len);
}

static void	print_unbr(unsigned int n, int fd, int *len)
{
	char	tmp;

	if (n / 10 != 0)
		print_unbr(n / 10, fd, len);
	tmp = n % 10 + '0';
	*len += write(fd, &tmp, 1);
}
