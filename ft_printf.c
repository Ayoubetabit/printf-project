/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:26:09 by atabit            #+#    #+#             */
/*   Updated: 2025/11/11 14:36:17 by atabit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	put_pointer(char *str, int *l, int *i, va_list args)
{
	void	*ptr;

	(*i)++;
	if (str[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", 1);
			(*i)++;
			(*l) += 5;
			return ;
		}
		ft_putstr_fd("0x", 1);
		(*l) += 2;
		putnbrbase((unsigned long)ptr, "0123456789abcdef", l, str[*i]);
		(*i)++;
	}
	else
		(*i)--;
}

static void	put_percent(char *str, int *l, int *i)
{
	(*i)++;
	if (str[*i] == '%')
	{
		ft_putchar_fd(str[*i], 1);
		(*l)++;
		(*i)++;
	}
	else
		(*i)--;
}

static void	check_print(char *str, int *l, int *i, va_list args)
{
	if (str[*i] == '%' && (str[(*i) + 1] == 'x' || str[(*i) + 1] == 'X'))
		put_hexa(str, l, i, args);
	else if (str[*i] == '%' && (str[(*i) + 1] == 's' || str[(*i) + 1] == 'c'))
		put_char_str(str, l, i, args);
	else if (str[*i] == '%' && (str[(*i) + 1] == 'i'
			|| str[(*i) + 1] == 'd' || str[(*i) + 1] == 'u'))
		put_int(str, l, i, args);
	else if (str[*i] == '%' && str[(*i) + 1] == 'p')
		put_pointer(str, l, i, args);
	else if (str[*i] == '%' && str[(*i) + 1] == '%')
		put_percent(str, l, i);
	else
	{
		ft_putchar_fd(str[*i], 1);
		(*i)++;
		(*l)++;
	}
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (str == NULL || write(1,"",0) < 0)
	{
		return (-1);
	}
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[(i) + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		check_print(str, &l, &i, args);
	}
	va_end(args);
	return (l);
}
