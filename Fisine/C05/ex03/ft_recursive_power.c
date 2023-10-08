/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:16:04 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/03 17:40:17 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power > 0)
		return (ft_recursive_power(nb, power - 1) * nb);
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	else
		return (0);
}
