/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:30:51 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/21 00:57:20 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != size - 1)
	{
		while (j != size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
/*
int	main(void)
{
	int i;
	printf("-ex08_test_case-\n\n");
	int tab1[7] = {15, 3, 0, 0, 5, 1, 8};
	printf("before :");
	i = 0;
	while(i < 7)
	{
		printf(" %d", tab1[i]);
		i++;
	}
	ft_sort_int_tab(tab1, 7);
	printf(" after :");
	i = 0;
	while(i < 7)
	{
		printf(" %d", tab1[i]);
		i++;
	}
}
*/
