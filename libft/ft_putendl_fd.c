/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:00:39 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/31 21:07:42 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *s);

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 1)
		return ;
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
