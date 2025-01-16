/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:15:40 by aserbest          #+#    #+#             */
/*   Updated: 2024/11/13 15:16:39 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_type(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(arg, unsigned long), "0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_u_putnbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_hexadecimal(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hexadecimal(va_arg(arg, unsigned long), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

static int	ft_format(va_list arg, const char *str)
{
	int	temp;
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			temp = ft_type(arg, str[++i]);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		sum;

	sum = 0;
	va_start(arg, str);
	sum = ft_format(arg, str);
	if (sum == -1)
	{
		va_end(arg);
		return (-1);
	}
	va_end(arg);
	return (sum);
}
