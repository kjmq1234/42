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

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;

	if (fd < 1)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		tmp = n % 10 + '0';
		write(fd, &tmp, 1);
	}
}
