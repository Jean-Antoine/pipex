/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:42 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 14:54:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-0# +"
# define WIDTH "0123456789.*"
# define TYPES "cspdiuxX%"
# define NUMERICTYPES "diouxX"
# define NUMERICSIGNEDTYPES "di"
# define DECBASE "0123456789"
# define HEXBASE "0123456789abcdef"
# define HEXBASEUP "0123456789ABCDEF"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

void	ft_putptr(void *ptr);
char	*ft_itostr(long long int n, char *base);
char	*ft_uitostr(size_t n, char *base);
char	*ft_ptrtostr(void *ptr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putcount_reset(void);
void	ft_putstr(char *str);
void	ft_putstr_f(char *str, size_t len);
int		ft_printf(const char *format, ...);
char	*ft_strapd_c(char *str, char c);
char	*ft_strppd_c(char *str, char c);

typedef struct s_field
{
	char			*str;
	char			type;
	int				width;
	int				precision;
	int				left;
	int				zero_padded;
	int				force_sign;
	char			sign_char;
	int				hex_prefix;
	int				negative;
	struct s_field	*next;
}	t_field;

t_field	*ft_newfld(void);
void	ft_clearfldlst(t_field **lst);
void	ft_readflags(char *format, t_field *field);
t_field	*ft_readformat(char *format);
void	ft_readparams(t_field *fields, va_list args);
char	*ft_strpadding(char *str, char c, size_t size, int left_align);
void	ft_applyprecision(t_field *field);
void	ft_applysign(t_field *field);
void	ft_applyhexprefix(t_field *field);
void	ft_applywidth(t_field *field);
void	ft_fldmap(t_field *field, void (*f)(t_field *));
#endif
