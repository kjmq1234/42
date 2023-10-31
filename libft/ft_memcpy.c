/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:02:58 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/31 17:51:09 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned int	i;
	void			*ptr;

	ptr = dst;
	i = 0;
	while (i < n)
	{
		if (dst != src)
		{
			*(unsigned char *) dst = *(unsigned char *) src;
			dst++;
			src++;
		}
		i++;
	}
	return (ptr);
}
