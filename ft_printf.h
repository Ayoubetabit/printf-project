/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:42:16 by atabit            #+#    #+#             */
/*   Updated: 2025/11/12 19:38:38 by atabit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(char *str, ...);
int		ft_nbrlen(long n, char *base);
void	putnbrbase(unsigned long n, char *base, int *i, char c);
void	put_int(char *str, int *l, int *i, va_list args);
void	put_char_str(char *str, int *l, int *i, va_list args);
void	put_hexa(char *str, int *l, int *i, va_list args);
#endif
