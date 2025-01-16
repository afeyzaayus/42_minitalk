/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:39:56 by aserbest          #+#    #+#             */
/*   Updated: 2024/10/26 22:04:45 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (s);
}
