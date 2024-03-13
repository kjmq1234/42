/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:49:10 by jaemikim          #+#    #+#             */
/*   Updated: 2024/03/10 13:43:01 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

void	print_pid(pid_t pid);
void	sig_handle(int signal);
void	make_send_str(pid_t pid, char *str);
void	send_packet(pid_t pid, char str);
void	make_send_pid(pid_t pid);
void	ack_handle(int signal);
int		get_pid(char byte);

#endif