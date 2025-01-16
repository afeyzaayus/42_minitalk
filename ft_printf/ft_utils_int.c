/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:33:21 by aserbest          #+#    #+#             */
/*   Updated: 2024/11/13 15:33:23 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
#include <unistd.h>

int	ft_putnbr(int n)
{
	char	c;
	int		len;
	int		temp;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
		len++;
	}
	if (n >= 10)
	{
		temp = ft_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	c = '0' + (n % 10);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_u_putnbr(unsigned int n)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 10)
	{
		temp = ft_u_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
