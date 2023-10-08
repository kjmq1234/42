/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:43:31 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 21:04:32 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(void)
{
	int div;
	int mod;

	div = 0;
	mod = 0;
	ft_div_mod(3, 2, &div, &mod);
	printf("answer div : 1  mod : 1\n\nyour result div : %d mod : %d", div, mod);
	printf("\n\n------------------------------\n\n");
}
*/
