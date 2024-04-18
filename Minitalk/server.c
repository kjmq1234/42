/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:51:04 by jaemikim          #+#    #+#             */
/*   Updated: 2024/04/19 00:06:00 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t				pid;
	struct sigaction	handler;

	pid = getpid();
	print_pid(pid);
	handler.sa_handler = sig_handle;
	handler.sa_flags = '\0';
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
}

void	sig_handle(int signal)
{
	static int		bit;
	static char		byte;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		bit = 0;
		byte = 0;
	}
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}
