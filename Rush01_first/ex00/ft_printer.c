/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejyoon <yejielin0823@student.42se>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:30:50 by yejyoon           #+#    #+#             */
/*   Updated: 2023/07/29 14:32:49 by yejyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	n_by_n_printer(int n, int *arr)
{
	int		i;
	char	num;

	i = 0;
	while (i < n * n)
	{
		num = *(arr + i) + '0';
		write(1, &num, 1);
		if (i % n != n - 1)
			write(1, " ", 1);
		if (i % n == n - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	ft_error_printer(void)
{
	char	*error;

	error = "Error";
	while (*error != 0)
	{
		write(1, error, 1);
		error++;
	}
	write(1, "\n", 1);
	return (0);
}
