/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:21:24 by nenvoy            #+#    #+#             */
/*   Updated: 2021/11/17 14:19:06 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		check_flag(const char *str, int i, va_list ap);
int		arg_c(va_list ap);
int		arg_s(va_list ap);
int		arg_p(va_list ap);
int		arg_d(va_list ap);
int		arg_u(va_list ap);
int		arg_x(va_list ap);
int		arg_upper_x(va_list ap);
int		ft_strlen(const char *s);
int		ft_hex_len(unsigned long hex);
void	ft_hex_convert(unsigned long hex, char *str);
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);
#endif