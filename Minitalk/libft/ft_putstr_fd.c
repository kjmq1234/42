/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:47 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 12:26:28 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		s = "(null)";
	if (fd < 1)
		return (-1);
	else
		return (write(fd, s, ft_strlen(s)));
}
