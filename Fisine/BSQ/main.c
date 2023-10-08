/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:21:47 by kyumkim           #+#    #+#             */
/*   Updated: 2023/08/10 11:14:56 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		cmd;

	cmd = 1;
	if (argc == 1)
	{
		dodp(0);
	}
	else
	{
		while (cmd < argc)
		{
			fd = open(argv[cmd], O_RDONLY);
			if (fd < 0)
				errprt();
			else
			{
				if (cmd != 1)
					write(1, "\n", 1);
				dodp(fd);
			}
			cmd++;
		}
	}
	return (0);
}

void	dodp(int fd)
{
	char	*buf;
	char	**input;
	t_inp	stinp;

	buf = stdinput(fd);
	input = ft_split(buf);
	if (*input == 0)
		errprt();
	first_str_check(input[0], &stinp);
	rowcolsame(input, &stinp);
	makearr(input, &stinp);
	dp(&stinp);
	print(&stinp);
}
