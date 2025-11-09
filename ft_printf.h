/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:42:16 by atabit            #+#    #+#             */
/*   Updated: 2025/11/09 10:53:17 by atabit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char *str, ...);
int		ft_nbrlen(long n, char *base);
void	putnbrbase(unsigned long n, char *base, int *i, char c);
void	put_int(char *str, int *l, int *i, va_list args);
void	put_char_str(char *str, int *l, int *i, va_list args);
void	put_hexa(char *str, int *l, int *i, va_list args);
#endif
