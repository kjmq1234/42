/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:18:55 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 13:07:30 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_data	info;
	va_list	ap;
	int		len;

	info.total_len = 0;
	va_start(ap, format);
	len = parse_info(format, &info, ap);
	va_end(ap);
	return (len);
}
