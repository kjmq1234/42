/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:08:03 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/03 17:40:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
		return (ft_recursive_factorial(nb - 1) * nb);
	else if (nb == 1)
		return (nb);
	else if (nb == 0)
		return (1);
	else
		return (0);
}
