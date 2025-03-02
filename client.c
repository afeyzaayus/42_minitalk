/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:35:22 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/25 17:51:20 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static int	g_client = 0;

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

static void	send_end_of_data(int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		while (g_client == 0)
			pause();
		g_client = 0;
		i--;
	}
}

static void	send_data(int pid, char *str)
{
	int	i;

	i = 7;
	while (*str)
	{
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_client == 0)
				pause();
			g_client = 0;
			i--;
		}
		str++;
		i = 7;
	}
	send_end_of_data(pid);
}

static void	detect_signal(int signal)
{
	if (signal == SIGUSR1)
		g_client = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	int						pid;
	struct sigaction		sa;

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
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = detect_signal;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_data(pid, argv[2]);
	return (0);
}
