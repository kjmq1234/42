/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:57:13 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 11:24:43 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	int	return_num;

	if (fd < 1)
		return (-1);
	return_num = write(fd, &c, 1);
	if (return_num == -1)
		return (-1);
	return (return_num);
}
