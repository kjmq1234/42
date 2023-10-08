/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:10 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/25 13:55:37 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i != n) && ((*s1 != '\0') || (*s2 != '\0')))
	{
		if ((unsigned char) *s1 > (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		else if ((unsigned char) *s1 < (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
