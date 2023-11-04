/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:04:06 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 17:26:03 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(const char *s);
int				ft_strlcat(char *dest, char *src, unsigned int size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if ((!s1) && (!s2))
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcat(str, (char *) s2, s2len + s1len + 1);
	return (str);
}
