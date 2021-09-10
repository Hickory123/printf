

#include "ft_printf.h"

void	minus(char **s, t_options *structure)
{
	if ((**s) == '-')
	{
		ft_putchar('-', 1, structure);
		(*s)++;
		structure->width--;
	}
}

void	structure_flag_zero(char **s, t_options *structure)
{
	if (structure->precision == -1)
		minus(s, structure);
	if (structure->precision != -1)
		structure->flag = -1;
	if (structure->flag == 0 && structure->width > ft_strlen(*s))
		ft_putchar('0', structure->width - ft_strlen(*s), structure);
}

void	structure_flag_minus_1(char *s, t_options *structure)
{
	if (structure->width > ft_strlen(s))
	{
		if (*s == '-' && structure->precision > ft_strlen(s))
			structure->width--;
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	}
}

int		intt(va_list ap, t_options *structure)
{
	int		d;
	char	*s;
	char	*temp;

	if (!(d = va_arg(ap, int)))
		structure->zero = 1;
	if (!(temp = itoa_base(d, 10)))
		return (-1);
	s = temp;
	if (structure->flag == 0)
		structure_flag_zero(&s, structure);
	if (structure->flag == -1)
		structure_flag_minus_1(s, structure);
	if (structure->precision != -1 && structure->precision >= ft_strlen(s))
	{
		minus(&s, structure);
		ft_putchar('0', structure->precision - ft_strlen(s), structure);
	}
	if (structure->precision || d)
		ft_putstr(s, structure);
	if (structure->flag == 1 && structure->width > ft_strlen(s))
		ft_putchar(' ', ct_spaces_d(ft_strlen(s), structure), structure);
	flags_init(structure);
	free(temp);
	return (0);
}

int		ct_spaces_d(int len, t_options *structure)
{
	int space;

	if (structure->precision > len ||\
	(structure->precision == 0 && structure->zero == 1))
	{
		space = structure->width - structure->precision;
		return (space);
	}
	space = structure->width - len;
	return (space);
}
