/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:19:10 by nenvoy            #+#    #+#             */
/*   Updated: 2021/11/17 14:25:11 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_x(va_list ap)
{
	unsigned int	hex;
	char			*str;

	str = "0123456789abcdef";
	hex = va_arg(ap, unsigned int);
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_hex_convert(hex, str);
	return (ft_hex_len(hex));
}

int	arg_upper_x(va_list ap)
{
	unsigned int	hex;
	char			*str;

	str = "0123456789ABCDEF";
	hex = va_arg(ap, unsigned int);
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_hex_convert(hex, str);
	return (ft_hex_len(hex));
}
