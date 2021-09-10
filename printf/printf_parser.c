

#include "ft_printf.h"

void	flags_init(t_options *structure)
{
	structure->flag = -1;
	structure->width = 0;
	structure->precision = -1;
	structure->zero = 0;
	structure->type = '\0';
}

int		type(char format, va_list ap, t_options *structure)
{
	int if_error;

	if_error = 0;
	if (format == (structure->type = 'c'))
		charr(ap, structure);
	else if (format == (structure->type = 'd'))
		if_error = intt(ap, structure);
	else if (format == (structure->type = 'i'))
		if_error = intt(ap, structure);
	else if (format == (structure->type = 's'))
		string(ap, structure);
	else if (format == (structure->type = 'u'))
		if_error = unsigned_int(ap, structure);
	else if (format == (structure->type = 'p'))
		if_error = pointer(ap, structure);
	else if (format == (structure->type = '%'))
		percent(structure);
	else if (format == (structure->type = 'X'))
		if_error = hex(ap, structure);
	else if (format == (structure->type = 'x'))
		if_error = hex(ap, structure);
	if (if_error)
		return (if_error);
	return (0);
}

void	flag(const char **format, t_options *structure)
{
	while (*(*format + 1) == '-' || *(*format + 1) == '0')
	{
		if (*(*format + 1) == '-')
			structure->flag = 1;
		if (*(*format + 1) == '0' && structure->flag != 1)
			structure->flag = 0;
		(*format)++;
	}
}

void	width(const char **format, t_options *structure, va_list ap)
{
	if (ft_isdigit(*(*format + 1)))
	{
		structure->width = ft_atoi(*format + 1);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	else if (*(*format + 1) == '*')
	{
		structure->width = va_arg(ap, int);
		if (structure->width < 0)
		{
			structure->width = structure->width * -1;
			structure->flag = 1;
		}
		(*format)++;
	}
}

void	prec(const char **format, t_options *structure, va_list ap)
{
	if (*(*format + 1) == '.')
	{
		structure->precision = 0;
		(*format)++;
		if (ft_isdigit(*(*format + 1)))
		{
			structure->precision = ft_atoi(*format + 1);
			while (ft_isdigit(*(*format + 1)))
				(*format)++;
		}
		else if (*(*format + 1) == '*')
		{
			structure->precision = va_arg(ap, int);
			(*format)++;
		}
	}
	if (structure->precision < 0)
		structure->precision = -1;
}
