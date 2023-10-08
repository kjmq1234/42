/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:05:03 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 21:21:47 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*
int main(void)
{
	int num1;
	int num2;

	num1 = 3;
	num2 = 2;
	ft_ultimate_div_mod(&num1, &num2);
	printf("answer div : 1  mod : 1\n\nyour result div : %d mod : %d", num1, num2);
	printf("\n\n------------------------------\n\n");
}
*/
