/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:56:26 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 18:20:53 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;
	void	*tmp;

	tmp = b;
	a = 0;
	while (a < len)
	{
		*(unsigned char *) tmp = (unsigned char) c;
		a++;
		tmp++;
	}
	return (b);
}
