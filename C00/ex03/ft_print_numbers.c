/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:13:33 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 16:24:46 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	a;

	a = '1';
	while (a <= '9' )
	{
		write(1, &a, 1);
		a++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
}
*/
