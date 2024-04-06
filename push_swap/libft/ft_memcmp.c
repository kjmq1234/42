/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:57:02 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 18:16:41 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *) s1 != *(unsigned char *) s2)
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
