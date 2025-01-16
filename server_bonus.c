#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

// Sinyal işleyici fonksiyonu
void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		ft_printf("Received SIGUSR1\n");
	else if (signum == SIGUSR2)
		ft_printf("Received SIGUSR2\n");
}

// Sinyal işleyiciyi ayarlayan fonksiyon
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

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n\n", pid);

	// Sinyal işleyiciyi ayarla
	signal_handler(handler);

	// Sonsuz döngü
	while (1)
		pause();
	return (0);
}
