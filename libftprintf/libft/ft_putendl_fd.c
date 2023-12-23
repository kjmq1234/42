/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:00:39 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/12 22:06:15 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 1)
		return ;
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
