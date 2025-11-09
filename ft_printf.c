/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:26:09 by atabit            #+#    #+#             */
/*   Updated: 2025/11/09 10:48:02 by atabit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	put_pointer(char *str, int *l, int *i, va_list args)
{
	void	*ptr;

	if (str[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", 1);
			(*l) += 5;
			return ;
		}
		ft_putstr_fd("0x", 1);
		(*l) += 2;
		putnbrbase((unsigned long)ptr, "0123456789abcdef", l, str[*i]);
	}
	else if (str[*i] == '%')
	{
		ft_putchar_fd(str[*i], 1);
		(*l)++;
	}
}

static void	check_print(char *str, int *l, int *i, va_list args)
{
	put_hexa(str, l, i, args);
	put_char_str(str, l, i, args);
	put_int(str, l, i, args);
	put_pointer(str, l, i, args);
	(*i)++;
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
		{
			return (-1);
			va_end(args);
		}
		if (str[i++] == '%')
			check_print(str, &l, &i, args);
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			l++;
		}
	}
	va_end(args);
	return (l);
}
