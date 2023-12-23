/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:03:30 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/11/12 19:18:35 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strdup(const char *s1);
static size_t	numlen(int n);
static void		into_buf(char *str, int n, int len);

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;

	len = numlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n > 0)
	{
		str = (char *) malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str = (char *) malloc(sizeof(char) * (len++ + 2));
		if (!str)
			return (0);
		n *= -1;
		str[0] = '-';
	}
	into_buf(str, n, len);
	return (str);
}

static void	into_buf(char *str, int n, int len)
{
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

static size_t	numlen(int n)
{
	int	cnt;

	cnt = 0;
	while (n != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}
