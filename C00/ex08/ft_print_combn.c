/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:09:23 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/22 23:25:16 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	downside(int n, int d, int f, char *buf);

void	ft_print_combn(int n)
{
	int		d;
	char	buf[9];

	d = 0;
	downside(n, 0, 0, buf);
}

void	downside(int n, int d, int f, char *buf)
{
	buf[d] = f + '0';
	while (f != 10)
	{
		buf[d] = f + '0';
		if (d == n - 1)
		{
			write(1, buf, d + 1);
			if ((buf[0] != '9' - d) || (buf[n - 1] != '9'))
				write(1, ", ", 2);
		}
		else
			downside(n, d + 1, f + 1, buf);
		f++;
	}
}

int	main(void)
{
	ft_print_combn(9);
}
