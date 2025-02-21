/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:41:27 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 20:13:23 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>


static volatile int g_server_signal = 0;

static int ft_isnumber(char *str)
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

static void send_end_of_data(pid_t pid)
{
    int i = 7;
    while (i >= 0)
    {
        kill(pid, SIGUSR2);
        while (g_server_signal == 0)
            pause();
        g_server_signal = 0;
        i--;
    }
}

static void send_message(pid_t pid, char *message)
{
    char i;

    i = 7;
    while (*message)
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
    send_end_of_data(pid); // Mesaj sonlanmadan önce çağırılır
}

static void handle_signal(int signal)
{
    if (signal == SIGUSR1)
        g_server_signal = 1;
    else
    {
        ft_putstr("MESSAGE RECEIVED\n");
        exit(0);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    pid_t pid;

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
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    send_message(pid, argv[2]);
    send_message(pid, "\0"); // Mesaj sonlandırma
    return (0);
}
