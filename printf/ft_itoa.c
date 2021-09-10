

#include "ft_printf.h"

static void		set_minus(long long int *num, int *minus, int base)
{
	if (*num < 0)
	{
		if (base == 10)
			*minus = 1;
		*num = *num * -1;
	}
}

static size_t	ft_amount(long num, int base)
{
	size_t i;

	i = 0;
	while (num)
	{
		num = num / base;
		i++;
	}
	return (i);
}

static void		ft_convert(char *s, long long int num, int base, int len)
{
	int		i;

	i = 1;
	while (num)
	{
		s[len - i++] = "0123456789abcdef"[num % base];
		num = num / base;
	}
	s[len] = '\0';
}

char			*itoa_base(long long int num, int base)
{
	char	*s;
	int		len;
	int		minus;

	minus = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (base == 10 && num == -2147483648)
		return (ft_strdup("-2147483648"));
	set_minus(&num, &minus, base);
	len = ft_amount(num, base) + minus;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (minus)
		s[0] = '-';
	ft_convert(s, num, base, len);
	return (s);
}
