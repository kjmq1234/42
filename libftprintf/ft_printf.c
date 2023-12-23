/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:18:55 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 01:47:47 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_data	*info;
	va_list	ap;
	int		len;

	info = (t_data *) calloc(1, sizeof(t_data));
	va_start(ap, format);
	len = parse_info(format, info, ap);
	if (len == -1)
	{
		free(info);
		va_end(ap);
		return (-1);
	}
	free(info);
	va_end(ap);
	return (len);
}
