

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_options
{
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		zero;
	char	type;
}				t_options;

int				ft_strlen(const char *s);
void			ft_putchar(char c, int n, t_options *structure);
void			ft_putstr(char *s, t_options *structure);
int				ft_printf(const char *format, ...);
int				ft_atoi(const char *nptr);
char			*itoa_base(long long int num, int base);
char			*ft_strdup(const char *s);
void			ft_toupper(char *c);
int				ft_isdigit(int c);
void			charr(va_list ap, t_options *structure);
void			string(va_list ap, t_options *structure);
int				unsigned_int(va_list ap, t_options *structure);
int				intt(va_list ap, t_options *structure);
int				pointer(va_list ap, t_options *structure);
int				hex(va_list ap, t_options *structure);
void			percent(t_options *structure);
int				type(char format, va_list ap, t_options *structure);
void			flag(const char **format, t_options *structure);
void			width(const char **format, t_options *structure, va_list ap);
void			prec(const char **format, t_options *structure, va_list ap);
void			flags_init(t_options *structure);
int				ct_spaces_str(int len, t_options *structure);
int				ct_spaces_d(int len, t_options *structure);
void			minus(char **s, t_options *structure);
void			structure_flag_zero(char **s, t_options *structure);
void			structure_flag_minus_1(char *s, t_options *structure);

#endif
