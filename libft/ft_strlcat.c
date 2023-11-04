/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:58:36 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 17:10:37 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	unsigned int	i;
	unsigned int	dstlen;
	unsigned int	srclen;

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
	if (dstlen > dstsize)
		return (dstsize + srclen);
	else
		return (dstlen + srclen);
}
