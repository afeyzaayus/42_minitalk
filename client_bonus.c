/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:42:22 by aserbest          #+#    #+#             */
/*   Updated: 2025/01/15 15:49:56 by aserbest         ###   ########.fr       */
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

static void received_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\nThis message received successfully.\n");
}

void	signal_handler(void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	ac;

	memset(&ac, 0, sizeof(struct sigaction));
	ac.sa_sigaction = handler;
	sigemptyset(&ac.sa_mask);
	sigaddset(&ac.sa_mask, SIGUSR1);
	sigaddset(&ac.sa_mask, SIGUSR2);
	ac.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &ac, NULL) < 0 || sigaction(SIGUSR2, &ac, NULL) < 0)
		ft_printf("Error: Handler setup failed.\n");
}

void	acknowledgement(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_acknowledgement = info->si_pid;
	else
		g_acknowledgement = -info->si_pid;
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
	signal_handler(acknowledgement);
	while (argv[2][i])
		transfer(pid, argv[2][i++]);
	transfer(pid, '\0');
	return (0);
}
