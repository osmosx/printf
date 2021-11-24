/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:54 by nenvoy            #+#    #+#             */
/*   Updated: 2021/11/16 15:00:31 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check_flag(str, i, ap);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

int	check_flag(const char *str, int i, va_list ap)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += arg_c(ap);
	else if (str[i] == 's')
		count += arg_s(ap);
	else if (str[i] == 'p')
		count += arg_p(ap);
	else if (str[i] == 'd' || str[i] == 'i')
		count += arg_d(ap);
	else if (str[i] == 'u')
		count += arg_u(ap);
	else if (str[i] == 'x')
		count += arg_x(ap);
	else if (str[i] == 'X')
		count += arg_upper_x(ap);
	else if (str[i] == '%')
	{
		write (1, "%", 1);
		count = 1;
	}
	return (count);
}
