/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:07:09 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:09:53 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	slen = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (0);
	while (i < slen)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
