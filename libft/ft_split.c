/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:39:13 by aserbest          #+#    #+#             */
/*   Updated: 2024/10/27 08:39:16 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	count_words(const char *str, char sep)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == sep)
			flag = 0;
		str++;
	}
	return (count);
}

static int	word_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != sep)
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			arr[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
			if (arr[i] == NULL)
				return (free_mem(arr));
			ft_strlcpy(arr[i], s, (word_len(s, c) + 1));
			s += word_len(s, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
