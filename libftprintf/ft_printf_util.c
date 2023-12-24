/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:00:52 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 15:51:25 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	parse_info(const char *format, t_data *info, va_list ap)
{
	int	return_write;

	if (!format)
		return (-1);
	while (*format != '\0')
	{
		while ((*format != '%') && (*format != '\0'))
		{
			return_write = write(1, format, 1);
			if (return_write == -1)
				return (-1);
			info->total_len += return_write;
			format++;
		}
		if (*format == '%')
		{
			format++;
			return_write = parse_flag(format, info);
			format += return_write;
			if ((print_val(format, info, ap) == -1) || (return_write == -1))
				return (-1);
			format++;
		}
	}
	return (info->total_len);
}

int	print_val(const char *format, t_data *info, va_list ap)
{
	int	return_write;

	return_write = 0;
	if ((*format == 'd') || (*format == 'i'))
		return_write = ft_putnbr_fd(va_arg(ap, int), 1, info);
	else if ((*format == 'x') || (*format == 'X'))
		return_write = print_hex(format, info, ap);
	else if (istype(format))
		return_write = print_other(format, info, ap);
	else
		return (-1);
	if (return_write == -1)
		return (-1);
	info->total_len += return_write;
	return (1);
}

int print_hex(const char *format, t_data *info, va_list ap)
{
	int	len;
	unsigned int val;

	len = 0;
	if ((info->empty == 1) || (info->plus == 1))
		return (-1);
	val = va_arg(ap, unsigned int);
	if (*format == 'x')
	{
		if ((info->hash == 1) && (val != 0))
			len += write(1, "0x", 2);
		len += ft_puthex_fd(val, 1);
		return (len);
	}
	else if (*format == 'X')
	{
		if ((info->hash == 1) && (val != 0))
			len += write(1, "0X", 2);
		len += ft_putuhex_fd(val, 1);
		return (len);
	}
	return (len);
}

int print_other(const char *format, t_data *info, va_list ap)
{
	int	len;

	len = 0;
	if ((info->empty == 1) || (info->plus == 1) || (info->hash == 1))
		return (-1);
	else if (*format == 'u')
		len = ft_putunbr_fd(va_arg(ap, unsigned int), 1);
	else if (*format == 'p')
		len = ft_putptr_fd(va_arg(ap, void *), 1);
	else if (*format == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'c')
		len = ft_putchar_fd(va_arg(ap, int), 1);
	else if (*format == '%')
		len = write(1, "%", 1);
	return (len);
}

int istype(const char *format)
{
	if ((*format == 'u') || (*format == 'p') || \
	(*format == 's') || (*format == 'c') || \
	(*format == 'c') || (*format == '%'))
		return (1);
	else
		return (0);
}