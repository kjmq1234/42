/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:04:06 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 01:49:45 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if ((!s1) && (!s2))
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcat(str, (char *) s2, s2len + s1len + 1);
	return (str);
}
