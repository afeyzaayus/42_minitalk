/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:43:03 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/28 14:31:43 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include <unistd.h>

static int	g_server = 0;

static void	handle_message(int signal)
{
	static char	c = 0;
	static int	i = 0;

	c = (c << 1) & ~1;
	if (signal == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		if (c == '\0')
			g_server = 1;
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	handle_message(signal);
	if (g_server == 1)
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
	struct sigaction	sa;

	ft_printf("\nSERVER PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
