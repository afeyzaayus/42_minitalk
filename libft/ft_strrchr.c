/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:57:59 by aserbest          #+#    #+#             */
/*   Updated: 2024/10/26 13:06:00 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	find;
	char	*ptr;

	find = (char)c;
	i = 0;
	ptr = 0;
	while (s[i])
	{
		if (s[i] == find)
			ptr = ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		ptr = ((char *)s + i);
	return (ptr);
}
