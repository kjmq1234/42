/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:00:35 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/21 00:29:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i != size / 2)
	{
		temp = tab[size - i - 1];
		tab[size - i -1] = tab[i];
		tab[i] = temp;
		i++;
	}
}
/*
int	main(void)
{
	printf("-ex07_test_case-\n\n");
	int tab[7] = {0, 1, 2, 3, 4, 5, 6};
	int i = 0;
	printf("before :");
	while(i < 7)
	{
		printf(" %d", tab[i]);
		i++;
	}
	ft_rev_int_tab(tab, 7);
	printf(" after :");
	i = 0;
	while(i < 7)
	{
		printf(" %d", tab[i]);
		i++;
	}
}
*/
