/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:58:45 by jaemikim          #+#    #+#             */
/*   Updated: 2024/03/10 13:43:45 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	handler;

	handler.sa_handler = ack_handle;
	handler.sa_flags = '\0';
	sigaction(SIGUSR1, &handler, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if ((pid > 99998) || (pid < 100))
			ft_putendl_fd("잘못된 pid입니다.", 1);
		make_send_str(pid, argv[2]);
	}
	else
	{
		ft_putendl_fd("잘못된 입력 값입니다.", 1);
	}
}

void	make_send_str(pid_t pid, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		send_packet(pid, str[idx]);
		idx++;
	}
	send_packet(pid, '\n');
	send_packet(pid, '\0');
	make_send_pid(pid);
}

void	make_send_pid(pid_t pid)
{
	pid_t	pid_c;
	char	*pid_ctostr;
	int		idx;

	pid_c = getpid();
	pid_ctostr = ft_itoa(pid_c);
	idx = 0;
	while (pid_ctostr[idx] != '\0')
	{
		send_packet(pid, pid_ctostr[idx]);
		idx++;
	}
	send_packet(pid, '\0');
}

void	send_packet(pid_t pid, char str)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((str & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	ack_handle(int signal)
{
	signal += 1;
	ft_putendl_fd("ACK 수신", 1);
}
