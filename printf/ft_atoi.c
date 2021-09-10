

#include "ft_printf.h"

static int	skip(const char *nptr, int *minus)
{
	int i;

	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f' || \
	nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*minus = -1;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *nptr)
{
	int				i;
	int				minus;
	unsigned long	result;

	minus = 1;
	result = 0;
	i = skip(nptr, &minus);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (!(ft_isdigit(nptr[i + 1])))
		{
			if (result > LONG_MAX - 1 && minus == -1)
				return (0);
			if (result > LONG_MAX && minus == 1)
				return (-1);
			return (result * minus);
		}
		i++;
	}
	return (0);
}
