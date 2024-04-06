/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:58:36 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:45:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst += dstlen;
	while ((dstlen + i + 1 < dstsize) && (*src != '\0'))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	if ((dstlen > dstsize) || (dstsize == 0))
		return (dstsize + srclen);
	else
		return (dstlen + srclen);
}
