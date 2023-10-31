/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:56:26 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/29 23:26:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	a;
	void			*tmp;

	tmp = b;
	a = 0;
	while (a < len)
	{
		*(unsigned char *) tmp = (unsigned char) c;
		a++;
		tmp++;
	}
	return (b);
}
