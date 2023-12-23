/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:00:52 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 03:43:31 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	parse_info(const char *format, t_data *info, va_list ap)
{
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		while ((*format != '%') && (*format != '\0'))
		{
			info->total_len += write(1, format, 1);
			format++;
		}
		if (*format == '%')
		{
			format++;
			if (print_val(format, info, ap) == -1)
				return (-1);
			format++;
		}
	}
	return (info->total_len);
}

int	print_val(const char *format, t_data *info, va_list ap)
{
	if ((*format == 'd') || (*format == 'i'))
		info->total_len += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'u')
		info->total_len += ft_putunbr_fd(va_arg(ap, unsigned int), 1);
	else if (*format == 'x')
		info->total_len += ft_puthex_fd(va_arg(ap, unsigned int), 1);
	else if (*format == 'X')
		info->total_len += ft_putuhex_fd(va_arg(ap, unsigned int), 1);
	else if (*format == 'p')
		info->total_len += ft_putptr_fd(va_arg(ap, void *), 1);
	else if (*format == 's')
		info->total_len += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'c')
	{
		info->total_len++;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else if (*format == '%')
		info->total_len += write(1, "%", 1);
	else
		return (-1);
	return (1);
}
