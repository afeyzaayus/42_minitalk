/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:43:03 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/21 13:08:22 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static int g_server = 0;

static void	handle_message(int signal)
{
	static char	c = 0;
	static char	i = 0;

	c = (c << 1) & ~1;
	if (signal == SIGUSR1)
    	c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
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
		write(1, "\n", 1);
		g_server = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\nSERVER PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

