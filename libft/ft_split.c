/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:17:02 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/11/04 18:23:35 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen_c(const char *s, char c);
int				wordcnt(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			strclear(char **s, unsigned int index);
char const		*str_jump(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char		**str;
	int			i;

	i = 0;
	str = (char **) malloc(sizeof(char *) * (wordcnt(s, c) + 1));
	if (!str)
		return (0);
	while (*s != '\0')
	{
		if ((*s != c) && (*s))
		{
			str[i] = (char *) malloc(sizeof(char) * (ft_strlen_c(s, c) + 1));
			if (!str[i])
			{
				strclear(str, i);
				return (0);
			}
			ft_strlcpy(str[i++], (char *) s, (ft_strlen_c(s, c) + 1));
			s = str_jump(s, c);
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}

int	wordcnt(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while ((*s == c) && (*s))
			s++;
		if ((*s != c) && (*s))
			cnt++;
		while ((*s != c) && (*s))
			s++;
	}
	return (cnt);
}

int	ft_strlen_c(const char *s, char c)
{
	int	len;

	len = 0;
	while ((*s != '\0') && (*s != c))
	{
		len++;
		s++;
	}
	return (len);
}

void	strclear(char **s, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (i < index)
		free(s[i++]);
	free(s);
	return ;
}

char const	*str_jump(const char *s, char c)
{
	while ((*s != c) && (*s))
		s++;
	return ((char const *) s);
}
