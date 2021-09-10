
#include "ft_printf.h"

void	ft_putchar(char c, int len, t_options *structure)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		structure->length++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	structure;
	int			if_error;

	va_start(ap, format);
	structure.length = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			flags_init(&structure);
			flag(&format, &structure);
			width(&format, &structure, ap);
			prec(&format, &structure, ap);
			if ((if_error = type(*(format + 1), ap, &structure)))
				return (if_error);
			format++;
		}
		else
			ft_putchar(*format, 1, &structure);
		if (*format != '\0')
			format++;
	}
	va_end(ap);
	return (structure.length);
}
