/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:43:03 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 20:03:25 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static int g_server = 0;

static void	decode_data(int signal)
{
	static char	c = 0;
	static char	i = 0;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c");
		i = 0;
		if (c == '\0')
		{
			g_server = 1;
			return;
		}
		c = 0;
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	decode_data(signal);
	if (g_server)
	{
		kill(info->si_pid, SIGUSR2);
		ft_printf("\n");
		g_server = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siginfo;

	ft_printf("\n\nSERVER PID: %d\n\n", getpid());
	siginfo.sa_flags = SA_SIGINFO;
	sigemptyset(&siginfo.sa_mask);
	siginfo.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &siginfo, NULL);
	sigaction(SIGUSR2, &siginfo, NULL);
	while (1)
		pause();
	return (0);
}

