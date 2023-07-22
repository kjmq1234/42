/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:40:11 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/22 14:55:29 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	rush(int x, int y);

int	main(void)
{
	    rush(5,5);
    write(1, "\n", 1);
    rush(2,5);
    write(1, "\n", 1);
    rush(1,5);
    write(1, "\n", 1);
    rush(0,5);
	  write(1, "\n", 1);
    rush(-1,5);
	  write(1, "\n", 1);
    rush(5,2);
    write(1, "\n", 1);
    rush(2,2);
    write(1, "\n", 1);
    rush(1,2);
    write(1, "\n", 1);
    rush(0,2);
	  write(1, "\n", 1);
    rush(-1,2);
	  write(1, "\n", 1);
    rush(5,1);
    write(1, "\n", 1);
    rush(2,1);
    write(1, "\n", 1);
    rush(1,1);
    write(1, "\n", 1);
    rush(0,1);
	  write(1, "\n", 1);
    rush(-1,1);
	  write(1, "\n", 1);
    rush(5,0);
    write(1, "\n", 1);
    rush(2,0);
    write(1, "\n", 1);
    rush(1,0);
    write(1, "\n", 1);
    rush(0,0);
	  write(1, "\n", 1);
    rush(-1,0);
	  write(1, "\n", 1);
    rush(5,-1);
    write(1, "\n", 1);
    rush(2,-1);
    write(1, "\n", 1);
    rush(1,-1);
    write(1, "\n", 1);
    rush(0,-1);
	  write(1, "\n", 1);
    rush(-1,-1);
	  write(1, "\n", 1);
	return (0);
}
