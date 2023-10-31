/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:32:59 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/31 17:46:53 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while ((*haystack != '\0') && (len > 0))
	{
		if (*haystack == *needle)
		{
			if (len >= (unsigned int) ft_strlen(needle))
			{
				if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
					return ((char *) haystack);
			}
		}
		haystack++;
		len--;
	}
	return (0);
}
