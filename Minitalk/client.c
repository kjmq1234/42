/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:58:45 by jaemikim          #+#    #+#             */
/*   Updated: 2024/03/09 23:06:37 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[])
{
    pid_t pid;

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
}

void	send_packet(pid_t pid, char str)
{
	int bit;

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