/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:14:29 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 17:16:55 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((void *) s);
		s++;
		n--;
	}
	return (0);
}
