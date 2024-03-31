/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:52:38 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 16:55:21 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*dststr;
	unsigned const char		*srcstr;

	srcstr = (const unsigned char *)src;
	dststr = (unsigned char *)dst;
	if ((!dst) && (!src))
		return (dst);
	if (dst <= src)
	{
		while (n--)
			*dststr++ = *srcstr++;
	}
	else
	{
		dststr += (n - 1);
		srcstr += (n - 1);
		while (n--)
			*dststr-- = *srcstr--;
	}
	return (dst);
}
