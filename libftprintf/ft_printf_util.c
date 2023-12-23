#include "ft_printf.h"
#include "libft/libft.h"

#include <stdlib.h>
#include <stdarg.h>

int parse_data(const char *format, t_data *info, va_list ap)
{

    if ((!format) || !istype(format))
        return (-1);
    while ((*format != '%') && (*format != '\0'))
    {
        info->total_len++;
        format++;
    }
    
}
