/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:00:39 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 23:16:37 by jam_min_2        ###   ########.fr       */
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
