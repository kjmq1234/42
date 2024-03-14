/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:51:04 by jaemikim          #+#    #+#             */
/*   Updated: 2024/03/14 12:22:41 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char byte;

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
	static int		pid;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if ((pid == 1) && (bit == 8))
	{
		pid = get_pid(byte);
		bit = 0;
		byte = 0;
	}
	else if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			pid = 1;
		byte = 0;
		bit = 0;
	}
}

int	get_pid(char byte)
{
	static char		pid_c[10];
	static int		idx;

	pid_c[idx++] = byte;
	if (byte == '\0')
	{
		kill(ft_atoi(pid_c), SIGUSR1);
		idx = 0;
		return (0);
	}
	return (1);
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}
