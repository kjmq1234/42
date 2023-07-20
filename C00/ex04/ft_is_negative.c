/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:15:10 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 16:26:16 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_is_negative(int n)
{
	char	a;

	if (n < 0)
	{
		a = 'N';
		write(1, &a, 1);
	}
	else
	{
		a = 'P';
		write(1, &a, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(1);
	ft_is_negative(0);
	ft_is_negative(-1);
}
*/
