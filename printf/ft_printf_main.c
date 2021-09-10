
#include "ft_printf.h"

void	charr(va_list ap, t_options *structure)
{
	char c;

	c = va_arg(ap, int);
	if ((structure->flag == -1 || structure->flag == 0) && structure->width > 1)
		ft_putchar(' ', structure->width - 1, structure);
	ft_putchar(c, 1, structure);
	if (structure->flag == 1 && structure->width > 1)
		ft_putchar(' ', structure->width - 1, structure);
	flags_init(structure);
}

void	string(va_list ap, t_options *structure)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (structure->flag == -1)
		ft_putchar(' ', ct_spaces_str(ft_strlen(s), structure), structure);
	if (structure->flag == 0 && structure->width > ft_strlen(s))
		ft_putchar('0', structure->width - ft_strlen(s), structure);
	ft_putstr(s, structure);
	if (structure->flag == 1)
		ft_putchar(' ', ct_spaces_str(ft_strlen(s), structure), structure);
	flags_init(structure);
}

int		pointer(va_list ap, t_options *structure)
{
	size_t	value;
	char	*s;

	if (!(value = va_arg(ap, size_t)))
		structure->zero = 1;
	if (!(s = itoa_base(value, 16)))
		return (-1);
	if (structure->flag == 0 && structure->precision != -1)
		structure->flag = -1;
	if (structure->flag == -1 && structure->width > (ft_strlen(s) + 2))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure) - 2, structure);
	ft_putstr("0x", structure);
	if (structure->precision != -1 && structure->precision > (ft_strlen(s)))
		ft_putchar('0', structure->precision - (ft_strlen(s)), structure);
	if (structure->flag == 0 && structure->width > (ft_strlen(s) + 2))
		ft_putchar('0', structure->width - (ft_strlen(s) + 2), structure);
	if (structure->precision || value)
		ft_putstr(s, structure);
	if (structure->flag == 1 && structure->width > (ft_strlen(s) + 2))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure) - 2, structure);
	flags_init(structure);
	free(s);
	return (0);
}

void	percent(t_options *structure)
{
	if (structure->flag == -1 && structure->width > 1)
		ft_putchar(' ', ct_spaces_str(1, structure), structure);
	if (structure->flag == 0 && structure->width > 1)
		ft_putchar('0', structure->width - 1, structure);
	ft_putchar('%', 1, structure);
	if (structure->flag == 1 && structure->width > 1)
		ft_putchar(' ', ct_spaces_str(1, structure), structure);
	flags_init(structure);
}

int		ct_spaces_str(int len, t_options *structure)
{
	int spaces;

	if (structure->precision == -1 || structure->precision > len)
		spaces = structure->width - len;
	else
		spaces = structure->width - structure->precision;
	if (spaces > 0)
		return (spaces);
	return (0);
}
