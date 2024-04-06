/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:40:47 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/23 19:51:03 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
    void *newptr;

    if (!ptr)
        return (0);
    if (size != 0)
    {
        newptr = (void*) ft_calloc(size, newptr);
        ft_memmove(newptr, ptr, size);
    }
    free(ptr);
    return (newptr);
}