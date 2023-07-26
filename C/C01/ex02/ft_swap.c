/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:24:11 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 19:30:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
		printf("-ex02_test_case-\n\n");
	int a = 42;
	int b = 26;
	printf("before | a : %d b : %d \n", a, b);
	ft_swap(&a, &b);
	printf("after | a : %d b : %d \b", a, b);
	printf("\n\n------------------------------\n\n");
}
*/
