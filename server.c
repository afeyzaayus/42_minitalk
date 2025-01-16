/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:43:03 by aserbest          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:04 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static void	handler(int signal)
{
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (-42)
		pause();
	return (0);
}
