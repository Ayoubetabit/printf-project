/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:42:04 by atabit            #+#    #+#             */
/*   Updated: 2025/11/09 10:55:34 by atabit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	putnbrbase(unsigned long n, char *base, int *i, char c)
{
	size_t	blen;

	blen = ft_strlen(base);
	if (n >= blen)
		putnbrbase(n / blen, base, i, c);
	if (c == 'x')
	{
		if (base[n % blen] >= 'A' && base[n % blen] <= 'F')
			ft_putchar_fd(ft_tolower(base[n % blen]), 1);
		else
			ft_putchar_fd(base[n % blen], 1);
		(*i)++;
	}
	else
	{
		ft_putchar_fd(base[n % blen], 1);
		(*i)++;
	}
}

int	ft_nbrlen(long n, char *base)
{
	int	x;
	int	l;

	l = ft_strlen(base);
	x = 1;
	if (n < 0)
	{
		x++;
		n = -n;
	}
	while (n >= l)
	{
		n = n / l;
		x++;
	}
	return (x);
}

void	put_hexa(char *str, int *l, int *i, va_list args)
{
	unsigned int	n;

	if ((str[*i] == 'x' || str[*i] == 'X'))
	{
		n = va_arg(args, unsigned int);
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			n = -n;
		}
		putnbrbase(n, "0123456789ABCDEF", l, str[*i]);
	}
}

void	put_char_str(char *str, int *l, int *i, va_list args)
{
	char	*s;

	if (str[*i] == 's')
	{
		s = va_arg(args, char *);
		if (!s)
		{
			ft_putstr_fd("(null)", 1);
			(*l) += 6;
			return ;
		}
		ft_putstr_fd(s, 1);
		(*l) += ft_strlen(s);
	}
	else if (str[*i] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*l)++;
	}
}

void	put_int(char *str, int *l, int *i, va_list args)
{
	unsigned int	a;
	int				n;

	if ((str[*i] == 'd' || str[*i] == 'i'))
	{
		n = va_arg(args, int);
		ft_putnbr_fd(n, 1);
		(*l) += ft_nbrlen(n, "0123456789");
	}
	if (str[*i] == 'u')
	{
		a = va_arg(args, unsigned int);
		putnbrbase(a, "0123456789", l, str[*i]);
	}
}
