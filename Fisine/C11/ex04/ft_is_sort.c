/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:28:55 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/08 17:09:45 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	flag = -1;
	i = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
		{
			if (flag == 1)
				return (0);
			flag = 0;
		}	
		else if ((*f)(tab[i - 1], tab[i]) < 0)
		{
			if (flag == 0)
				return (0);
			flag = 1;
		}
		i++;
	}
	return (1);
}
