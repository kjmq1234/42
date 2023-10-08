/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c00_test_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:50:04 by hyehan            #+#    #+#             */
/*   Updated: 2023/07/23 22:44:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
#include "ex08/ft_print_combn.c"
#include <stdio.h>

int	main(void)
{
	printf("-ex00_test_case-\n\n");
	ft_putchar('a');
	printf("\n\n------------------------------\n\n");

	printf("-ex01_test_case-\n\n");
	ft_print_alphabet();
	printf("\n\n------------------------------\n\n");

	printf("-ex02_test_case-\n\n");
	ft_print_reverse_alphabet();
	printf("\n\n------------------------------\n\n");

	printf("-ex03_test_case-\n\n");
	ft_print_numbers();
	printf("\n\n------------------------------\n\n");

	printf("-ex04_test_case-\n\n");
	printf("answer : NPP\n");
	ft_is_negative(-1);
	printf("\n");
	ft_is_negative(1);
	printf("\n");
	ft_is_negative(0);
	printf("\n");
	printf("\n\n------------------------------\n\n");

	printf("-ex05_test_case-\n\n");
	ft_print_comb();
	printf("\n\n------------------------------\n\n");

	printf("-ex06_test_case-\n\n");
	ft_print_comb2();
	printf("\n\n------------------------------\n\n");

	printf("-ex07_test_case-\n\n");
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(-42);
	printf("\n");
	printf("\n\n------------------------------\n\n");

	printf("-ex08_test_case-\n\n");
	printf("input : 3\n\n");
	ft_print_combn(3);
	printf("\n\n");
	printf("input : 9\n\n");
	ft_print_combn(9);
	printf("\n\n------------------------------\n\n");

	return 0;
}
