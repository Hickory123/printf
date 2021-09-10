

#include "ft_printf.h"

int	hex(va_list ap, t_options *structure)
{
	unsigned int	hex;
	char			*s;

	if (!(hex = va_arg(ap, unsigned int)))
		structure->zero = 1;
	if (!(s = itoa_base(hex, 16)))
		return (-1);
	if (structure->type == 'X')
		ft_toupper(s);
	if (structure->flag == 0 && structure->precision != -1)
		structure->flag = -1;
	if (structure->flag == -1 && structure->width > ft_strlen(s))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	if (structure->flag == 0 && structure->width > ft_strlen(s))
		ft_putchar('0', structure->width - ft_strlen(s), structure);
	if (structure->precision != -1 && structure->precision > ft_strlen(s))
		ft_putchar('0', structure->precision - ft_strlen(s), structure);
	if (structure->precision || hex)
		ft_putstr(s, structure);
	if (structure->flag == 1 && structure->width > ft_strlen(s))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	flags_init(structure);
	free(s);
	return (0);
}

int	unsigned_int(va_list ap, t_options *structure)
{
	unsigned int	u;
	char			*s;

	if (!(u = va_arg(ap, unsigned int)))
		structure->zero = 1;
	if (!(s = itoa_base(u, 10)))
		return (-1);
	if (structure->flag == 0 && structure->precision != -1)
		structure->flag = -1;
	if (structure->flag == -1 && structure->width > ft_strlen(s))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	if (structure->flag == 0 && structure->width > ft_strlen(s))
		ft_putchar('0', structure->width - ft_strlen(s), structure);
	if (structure->precision != -1 && structure->precision > ft_strlen(s))
		ft_putchar('0', structure->precision - ft_strlen(s), structure);
	if (structure->precision || u)
		ft_putstr(s, structure);
	if (structure->flag == 1 && structure->width > ft_strlen(s))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	flags_init(structure);
	free(s);
	return (0);
}
