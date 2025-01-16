/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:14:08 by aserbest          #+#    #+#             */
/*   Updated: 2024/11/16 11:44:12 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int n, char *hex)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 16)
	{
		temp = ft_hexadecimal(n / 16, hex);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_putchar(hex[n % 16]);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

int	ft_ptr_hex(unsigned long n, char *hex)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 16)
	{
		temp = ft_ptr_hex(n / 16, hex);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_putchar(hex[n % 16]);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

int	ft_pointer(unsigned long n, char *hex)
{
	int	len;
	int	temp;

	len = 2;
	if (n == 0)
		return (ft_putstr("(nil)"));
	if (ft_putchar('0') == -1 || ft_putchar('x') == -1)
		return (-1);
	temp = ft_ptr_hex(n, hex);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
