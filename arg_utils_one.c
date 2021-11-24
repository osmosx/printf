/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:02 by nenvoy            #+#    #+#             */
/*   Updated: 2021/11/17 14:26:51 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	arg_s(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str)
	{
		while (str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_strlen(str));
}

int	arg_p(va_list ap)
{
	unsigned long	hex;
	char			*str;

	str = "0123456789abcdef";
	hex = (unsigned long)va_arg(ap, void *);
	write (1, "0x", 2);
	if (hex == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		ft_hex_convert(hex, str);
	return (ft_hex_len(hex) + 2);
}

int	arg_d(va_list ap)
{
	int	d;
	int	i;

	i = 0;
	d = va_arg(ap, int);
	ft_putnbr(d);
	if (d == 0)
		i++;
	if (d < 0)
	{
		i++;
		d *= -1;
	}
	while (d)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

int	arg_u(va_list ap)
{
	unsigned int	u;
	int				i;

	i = 0;
	u = va_arg(ap, unsigned int);
	ft_putnbr_u(u);
	if (u == 0)
		i++;
	while (u)
	{
		u = u / 10;
		i++;
	}
	return (i);
}
