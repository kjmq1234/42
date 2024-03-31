/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:58:57 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:45:35 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (0);
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
