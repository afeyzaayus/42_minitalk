/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:44:15 by aserbest          #+#    #+#             */
/*   Updated: 2024/10/26 22:53:36 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		count++;
		number = -number;
	}
	if (number == 0)
		count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*negative(char *str, int n, int len)
{
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", len + 1);
		return (str);
	}
	n = -n;
	str[len--] = '\0';
	while (len > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

static char	*positive(char *str, int n, int len)
{
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		return (negative(str, n, len));
	return (positive(str, n, len));
}
