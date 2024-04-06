/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:40:47 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:48:40 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if ((!ptr) || (size == 0))
		return (0);
	newptr = (void *) malloc(size);
	ft_memmove(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
