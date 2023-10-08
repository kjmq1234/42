/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:17:00 by kyumkim           #+#    #+#             */
/*   Updated: 2023/08/10 11:16:31 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*stdinput(int fd)
{
	int		buf_size;
	int		read_size;
	char	*buffer;
	int		flag;

	buf_size = 8;
	buffer = malloc(sizeof(char) * (buf_size));
	if (buffer == 0)
		errprt();
	read_size = read(fd, buffer, buf_size);
	flag = read_size;
	while (flag != 0)
	{
		if (read_size == buf_size)
		{
			buffer = vecdup(buffer, buf_size);
			buf_size = buf_size * 2;
		}
		flag = read(fd, buffer + read_size, buf_size - read_size);
		read_size = read_size + flag;
	}
	null_check(buffer, read_size);
	buffer = vecdup(buffer, buf_size);
	buffer[read_size] = '\0';
	return (buffer);
}

char	*vecdup(char *buf, int buf_size)
{
	char	*ret;
	int		idx;

	idx = 0;
	ret = malloc(sizeof(char) * (buf_size * 2));
	while (idx < buf_size)
	{
		ret[idx] = buf[idx];
		idx++;
	}
	free(buf);
	return (ret);
}

void	null_check(char *buf, int read_size)
{
	int		idx;

	idx = 0;
	while (idx < read_size)
	{
		if (buf[idx] == '\0')
		{
			write (2, "map error\n", 10);
			exit(1);
		}
		idx++;
	}
}
