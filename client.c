/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:41:27 by aserbest          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:10 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static int	ft_isnumber(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

static void	transfer(int pid, char c)
{
	int	bits;

	bits = -1;
	while (++bits < 8)
	{
		kill(pid, (SIGUSR2 - SIGUSR1) * (c >> bits & 1) + SIGUSR1);
		usleep(250);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Please enter 3 arguments!!!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!ft_isnumber(argv[1]) || pid <= 0 || kill(pid, 0) < 0)
	{
		ft_printf("ERROR!!! Invalid ID!\n");
		return (1);
	}
	while (argv[2][i])
		transfer(pid, argv[2][i++]);
	transfer(pid, '\0');
	return (0);
}
