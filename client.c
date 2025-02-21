static _Bool	g_server_signal = 0;

static void	send_message(pid_t pid, char *message)
{
	char	i;

	i = 7;
	while (*message || *message == '\0')
	{
		while (i >= 0)
		{
			if ((*message >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_server_signal == 0)
				pause();
			g_server_signal = 0;
			i--;
		}
		message++;
		i = 7;
	}
}

static void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_server_signal = 1;
	else
	{
		ft_putstr("MESSGAE RECEIVED\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	siginfo;
	pid_t				pid;

	if (argc != 3)
	{
		ft_putstr("Invalid pattern!");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_putstr ("Invalid PID!");
		return (-1);
	}
	siginfo.sa_handler = handle_signal;
	sigemptyset(&siginfo.sa_mask);
	siginfo.sa_flags = 0;
	sigaction(SIGUSR1, &siginfo, NULL);
	sigaction(SIGUSR2, &siginfo, NULL);
	send_message(pid, argv[2]);
	send_message(pid, "\0");
	return (0);
}