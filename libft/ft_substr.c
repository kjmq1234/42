/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:58:57 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/31 18:12:16 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char				*str;
	unsigned int		slen;

	if ((unsigned int) ft_strlen(s) < start)
		return (ft_strdup(""));
	s += start;
	slen = ft_strlen(s);
	if (slen >= len)
	{
		str = (char *) malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, s, len + 1);
		return (str);
	}
	else
		return (ft_strdup(s));
}
