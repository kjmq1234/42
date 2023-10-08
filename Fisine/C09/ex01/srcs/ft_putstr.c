/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:23:09 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/24 16:28:21 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}
/*
int	main(void)
{
	ft_putstr("42");
	ft_putstr("조현근");
	ft_putstr("양파쿵야");
	ft_putstr("chaypark");
	ft_putstr(" Let's Go");
}
*/
